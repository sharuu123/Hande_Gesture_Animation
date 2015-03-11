
// Hand Gesture Animation
// BTP Project - 2011
// Indian Institute of Technology, Guwahati.

// Project Memebers:
// Sharath Chandra Darsha
// Chaitanya Narra

#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
#include "cxcore.h"
#include "iostream"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/freeglut.h>
#define pi 3.1412
#include "imageloader.h"
using namespace std;

//....................................................................................................................
// ANIMATION


// opengl2.cpp : Defines the entry point for the console application.
//



#define Ltheta1 angles1[0]
#define Ltheta2 angles1[1]
#define Ltheta3 angles1[2]
#define Rtheta1 angles1[3]
#define Rtheta2 angles1[4]
#define Rtheta3 angles1[5]
#define Mtheta1 angles1[6]
#define Mtheta2 angles1[7]
#define Mtheta3 angles1[8]
#define Itheta1 angles1[9]
#define Itheta2 angles1[10]
#define Itheta3 angles1[11]
#define Ttheta1 angles1[12]
#define Ttheta2 angles1[13]

#define COLORTYPE GLU_LINE
#define COLORTYPE1 GLU_LINE

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}


GLuint _textureId;

double angles2[14]={180,270,90,180,270,90,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
double angles1[14]={180,270,90,180,270,90,180,270,90,180,270,90,90,90};
//double *angle1=&angles1;
//double *angle2=&angles2;

int count1=0,it=0;
int temporary=1;

void initRendering() 
{
	Image* image = loadBMP("skin.bmp");
	_textureId = loadTexture(image);
	delete image;
}

GLsizei winWidth=500,winHeight=500;




void init(void)
{
	glClearColor(1.0,1.0,1.0,1);
	//gluLookAt(1,0,0,0,0,0,0,0,1);
	//gluLookAt(0,1,0,0,0,0,0,0,1);		// Front View
	gluLookAt(.6,1,.7,0,0,0,0,0,1);
}

void wireQuadSurfs(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//gluLookAt(0,1,0,0,0,0,0,0,1);			// along yiaxis
	//gluLookAt(.6,1,.7,0,0,0,0,0,1);
//...................................................................................................................
	
	  glColor3f(.6,.5,.6);
	  glBegin(GL_LINES);
		
		glVertex3f(-3,0,0);
		glVertex3f(3,0,0);
		glVertex3f(0,-3,0);
		glVertex3f(0,3,0);
		glVertex3f(0,0,-3);
	    glVertex3f(0,0,3);
	    glEnd();



	  glEnable(GL_TEXTURE_2D);
	  glBindTexture(GL_TEXTURE_2D, _textureId);

      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glColor3f(1.0f, 1.0f, 1.0f);
		
	
	glBegin(GL_QUADS);
		//glColor3f(0.9f,0.7921f,0.7607f);
		
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(2.15,1.2,-1);
		
		
		glTexCoord2f(5.0f, 5.0f);
		glVertex3f(-1.15,1.2,-1);
		
		glTexCoord2f(5.0f, 5.0f);
		glVertex3f(-1.15,1.2,-1);
		
		glTexCoord2f(5.0f, 5.0f);
		glVertex3f(-1.15,1.2,-4);

		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.15,1.2,-4);
		glVertex3f(2.15,1.2,-4);
		glVertex3f(2.15,1.2,-4);
		glVertex3f(2.15,1.2,-1);
	    glEnd();

	/*	glVertex3f(2,1.2,-1);
		glVertex3f(-1,1.2,-1);
		glVertex3f(-1,1.2,-1);
		glVertex3f(-1,1.2,-4);
		glVertex3f(-1,1.2,-4);
		glVertex3f(2,1.2,-4);
		glVertex3f(2,1.2,-4);
		glVertex3f(2,1.2,-1); */
		
		glBegin(GL_QUADS);
		glVertex3f(2.15,0.8,-1);
		glVertex3f(2.15,1.2,-1);
		glVertex3f(2.15,0.8,-4);
		glVertex3f(2.15,1.2,-4);
		glEnd();


		glBegin(GL_QUADS);
		glVertex3f(-1.15,0.8,-1);
		glVertex3f(-1.15,1.2,-1);
	    glVertex3f(-1.15,0.8,-4);
		glVertex3f(-1.15,1.2,-4);
		glEnd();
		
		glBegin(GL_QUADS);
		glVertex3f(2.15,.8,-1);
		glVertex3f(-1.15,.8,-1);
		glVertex3f(-1.15,.8,-1);
		glVertex3f(-1.15,.8,-4);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-1.15,.8,-4);
		glVertex3f(2.15,.8,-4);
		glVertex3f(2.15,.8,-4);
		glVertex3f(2.15,.8,-1);
	    glEnd();
//...................................................................................................................
		glColor3f(0,0,0);
		glBegin(GL_POINTS);
		glVertex3f(-3,0,0);
		glVertex3f(3,0,0);
		glVertex3f(0,-3,0);
		glVertex3f(0,3,0);
		glVertex3f(0,0,-3);
		glVertex3f(0,0,3);
	glEnd();


//...................................................................................................................
	/*int k[]={1,0,-1};

	int i;
	for(i=0;i<3;i++)
	{
		glPushMatrix();
		glTranslatef(k[i],1,0);
		glutWireSphere(0.15,8,6);
		glPopMatrix();
	}*/
//...................................................................................................................
	glColor3f(0,0,0);
//...................................................................................................................
	//Little finger
	
	double theta1=0,theta2=0,theta3=0;
	double x,y,z,x1,y1,z1;

	theta1=-Ltheta1;
	theta2=-Ltheta2;
	theta3=-Ltheta3;

	y=cos((90+theta1)*22/(7*180));
	z=sin((90+theta1)*22/(7*180));

	y1=cos((90+theta3)*22/(7*180));
	z1=sin((90+theta3)*22/(7*180));

	
	
	glPushMatrix();					// Intermediate Proximal Phalangel
	glTranslatef(2,1+y1,z1-1);
	glutWireSphere(0.15,8,6);
	glPopMatrix();

	glPushMatrix();					// Distal Intermediate Phalangel
	glTranslatef(2,(1+y+y1),(z+z1-1));
	glutWireSphere(0.15,8,6);
	glPopMatrix();

	glColor3f(1,0,0);


     //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	 //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     //glColor3f(1.0f, 1.0f, 1.0f);

	GLUquadricObj *cylinder1;
	glPushMatrix();
	glTranslatef(2,1+y1,z1-1);
	glRotatef(theta1,1,0,0);
	cylinder1 = gluNewQuadric();
	gluQuadricTexture(cylinder1,GL_TRUE);
	gluQuadricDrawStyle(cylinder1,COLORTYPE);
	gluCylinder(cylinder1,0.18,0.1675,1,6,1);
	glPopMatrix();

	GLUquadricObj *cylinder5;
	glPushMatrix();
	glTranslatef(2,(1+y+y1),(z+z1-1));
	glRotatef(theta2,1,0,0);
	cylinder5 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder5,COLORTYPE1);
	gluCylinder(cylinder5,0.1675,0.1075,1,6,1);
	glPopMatrix();

	GLUquadricObj *cylinder9;
	glPushMatrix();
	glTranslatef(2,1,-1);
	glRotatef(theta3,1,0,0);
	cylinder9 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder9,COLORTYPE);
	gluCylinder(cylinder9,0.18,0.18,1,6,1);
	glPopMatrix();

//...................................................................................................................
	//Ring Finger
	glColor3f(0,0,0);

	theta1=-Rtheta1;
	theta2=-Rtheta2;
	theta3=-Rtheta3;

	y=cos((90+theta1)*22/(7*180));
	z=sin((90+theta1)*22/(7*180));

	y1=cos((90+theta3)*22/(7*180));
	z1=sin((90+theta3)*22/(7*180));

	glPushMatrix();
	glTranslatef(1,1+y+y1,z+z1-1);
	glutWireSphere(0.15,8,6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,1+y1,z1-1);
	glutWireSphere(0.15,8,6);
	glPopMatrix();

	glColor3f(1,0,0);

//middle phalange
	GLUquadricObj *cylinder2;
	glPushMatrix();
	glTranslatef(1,y1+1,0+z1-1);
	glRotatef(theta1,1,0,0);
	cylinder2 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder2,COLORTYPE);
	gluCylinder(cylinder2,0.2,0.1875,1,6,1);
	glPopMatrix();
//top phalange
		GLUquadricObj *cylinder6;
	glPushMatrix();
	glTranslatef(1,1+y+y1,z+z1-1);
		glRotatef(theta2,1,0,0);
	cylinder6 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder6,COLORTYPE1);
	gluCylinder(cylinder6,0.1875,0.1275,1,6,1);
	glPopMatrix();

	GLUquadricObj *cylinder10;
	glPushMatrix();
	glTranslatef(1,1,-1);
	glRotatef(theta3,1,0,0);
	cylinder10 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder10,COLORTYPE);
	gluCylinder(cylinder10,0.2,0.2,1,6,1);
	glPopMatrix();
//...................................................................................................................
	// Middle Finger
	glColor3f(0,0,0);

	theta1=-Mtheta1;
	theta2=-Mtheta2;
	theta3=-Mtheta3;

	y=cos((90+theta1)*22/(7*180));
	z=sin((90+theta1)*22/(7*180));

	y1=cos((90+theta3)*22/(7*180));
	z1=sin((90+theta3)*22/(7*180));

	glPushMatrix();
	glTranslatef(0,1+y+y1,z+z1-1);
	glutWireSphere(0.15,8,6);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(0,1+y1,-1+z1);
	glutWireSphere(0.15,8,6);
	glPopMatrix();
	

	glColor3f(1,0,0);

//middle phalange
	GLUquadricObj *cylinder3;
	glPushMatrix();
	glTranslatef(0,1+y1,0+z1-1);
	glRotatef(theta1,1,0,0);
	cylinder3 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder3,COLORTYPE);
	gluCylinder(cylinder3,0.2,0.1875,1,6,1);
	glPopMatrix();

//top phalange
	GLUquadricObj *cylinder7;
	glPushMatrix();
	glTranslatef(0,1+y+y1,z+z1-1);
		glRotatef(theta2,1,0,0);
	cylinder7 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder7,COLORTYPE1);
	gluCylinder(cylinder7,0.1875,0.1275,1,6,1);
	glPopMatrix();

//bottom phalange
	GLUquadricObj *cylinder11;
	glPushMatrix();
	glTranslatef(0,1,-1);
	glRotatef(theta3,1,0,0);
	cylinder11 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder11,COLORTYPE1);
	gluCylinder(cylinder11,0.2,0.2,1,6,1);
	glPopMatrix();


//...................................................................................................................
	//Index Finger
	glColor3f(0,0,0);

	theta1=-Itheta1;
	theta2=-Itheta2;
	theta3=-Itheta3;

	y=cos((90+theta1)*22/(7*180));
	z=sin((90+theta1)*22/(7*180));

	y1=cos((90+theta3)*22/(7*180));
	z1=sin((90+theta3)*22/(7*180));

	glPushMatrix();
	glTranslatef(-1,1+y+y1,z+z1-1);
	glutWireSphere(0.1,8,6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,1+y1,0+z1-1);
	glutWireSphere(0.15,8,6);
	glPopMatrix();
	

	glColor3f(1,0,0);

	GLUquadricObj *cylinder4;
	glPushMatrix();
	glTranslatef(-1,1+y1,0+z1-1);
	glRotatef(theta1,1,0,0);
	cylinder4 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder4,COLORTYPE);
	gluCylinder(cylinder4,0.2,0.1875,1,6,1);
	glPopMatrix();


	GLUquadricObj *cylinder8;
	glPushMatrix();
	glTranslatef(-1,1+y+y1,z+z1-1);
		glRotatef(theta2,1,0,0);
	cylinder7 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder7,COLORTYPE1);
	gluCylinder(cylinder7,0.1875,0.1275,1,6,1);
	glPopMatrix();

	GLUquadricObj *cylinder12;
	glPushMatrix();
	glTranslatef(-1,1,-1);
	glRotatef(theta3,1,0,0);
	cylinder12 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder12,COLORTYPE);
	gluCylinder(cylinder12,0.2,0.2,1,6,1);
	glPopMatrix();


//..............................................................................................................	
	//Thumb
	glColor3f(0,0,0);

	theta1=Ttheta1;
	theta2=Ttheta2;

	x=cos((90+theta1)*22/(7*180));
	z=sin((90+theta1)*22/(7*180));

	glPushMatrix();
	glTranslatef(-1.65,1+sin(22.0/21),-3+cos(22.0/21)+0.1);
	glutWireSphere(0.15,8,6);
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(-1.65-x,1+sin(22.0/21),-3+z+cos(22.0/21)+0.1);
	glutWireSphere(0.15,8,6);
	glPopMatrix();*/

	glColor3f(1,0,0);

	GLUquadricObj *cylinder13;
	glPushMatrix();
	glTranslatef(-1.65,1+sin(22.0/21),-3+cos(22.0/21)+0.1);
	glRotatef(theta1,0,1,0);
	cylinder13 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder13,COLORTYPE);
	gluCylinder(cylinder13,0.3,0.2,1,6,1);
	glPopMatrix();

/*
	GLUquadricObj *cylinder14;
	glPushMatrix();
	glTranslatef(-1.65-x,1+sin(22.0/21),-3+z+cos(22.0/21)+0.1);
		glRotatef(theta2,0,1,0);
	cylinder14 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder14,COLORTYPE1);
	gluCylinder(cylinder14,0.2,0.17,1,6,1);
	glPopMatrix(); */

	GLUquadricObj *cylinder15;
	glPushMatrix();
	glTranslatef(-1.15,1,-4+cos(22.0/21));
	glRotatef(-60,0,1,0);
	cylinder15 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder15,COLORTYPE);
	gluCylinder(cylinder15,0.4,0.3,1,6,1);
	glPopMatrix();
//..............................................................................................................	

	glutSwapBuffers();

	glFlush();
	
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0,0,newWidth,newHeight);

	glMatrixMode(GL_PROJECTION);
	glOrtho(-8,8,-8,8,-8,8);

	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT);
}



void animate(void)
{
	int a=0,b=0,c=0;
	int i,k;
	
	for(k=0;k<10;k++)
	{
	for(i=0;i<200000;i++);
	}

	temporary=0;

	if(angles1[it]<180 && angles1[it+1]<270 && angles1[it]<(angles2[it]))
	{
	angles1[it]+=2;
	angles1[it+1]+=3;
	a=1;
	temporary=1;
	}

	else
		if(angles1[it]>(angles2[it]+3))
		{
			angles1[it]-=2;
			angles1[it+1]-=3;
			a=1;
			temporary=1;
		}
	

	if(angles1[it+2]<90 && angles1[it+2]<angles2[it+2])
	{angles1[it+2]+=1;
	b=1;
	temporary=1;
	}

	else
		if( angles1[it+2]>angles2[it+2])
		{
		angles1[it+2]-=1;
		b=1;
		temporary=1;
		}
		
   if(a==0 && b==0 && it<=11)
   { it=it+3;
	temporary=1;
	c=1;
   }

   if(a==0 && b==0 && c==0)
   {
	//glutLeaveMainLoop();	
   temporary=0;
   it=0;
   }

	glutPostRedisplay();

}

void mouseFcn(GLint button, GLint action, GLint x, GLint y)
{
	switch(button) {
		case GLUT_LEFT_BUTTON:
			if (action==GLUT_DOWN)
			{
				//glutIdleFunc(rotateHand);
				count1++;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			if (action==GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
	}


}




//....................................................................................................................
// ANIMATION


using namespace std;
int th=200;

struct num{	
	unsigned char H;
	unsigned char S;
	unsigned char V;
};

struct num **bmpdata;
int thresh;
int xmax=0,ymax=0;
int ymin=1000,xmin=1000;



int* findlocmaxmin(long int *a)
{
		int j,temp,temp1=0;
	int len=181;
	int *max=new int[20];
	cout<<endl;

		for(j=0;j<len;j++)
		{
			temp=0;
			if(j>4 && a[j]>=a[j+1] && a[j]>=a[j+2] && a[j]>=a[j+3] && a[j]>=a[j+4] && a[j]>=a[j+5] && j<len-5 && a[j]>=a[j-1] && a[j]>=a[j-2] && 

a[j]>=a[j-3] && a[j]>=a[j-4] && a[j]>=a[j-5])
			{
				if( (a[j]>1.15*a[j+5]) || (a[j]>1.15*a[j+4]) || (a[j]>1.15*a[j+6]))
				{
				max[temp1]=j;
				temp1++;
			    }
			
			
				else if(j>30 && j<=110)
				{
					
							max[temp1]=j;
							temp1++;
						
				}	
				
			
				else 
					continue;
			}

		}
max[temp1]=-1;

return max;

}




long int* RadialSignature(IplImage* img,int xc ,int yc)
{
   FILE *fp;
   fp=fopen("asdf.dat","w");
   int i,j;

   long int *sig=new long int[181];
   float the=-90.0;
   for(int i=0;i<181;i++)
   {
		sig[i]=0;
   }


    for (the=-90.0;the<=90.0;the+=1)
	{
		for(i=ymin;i<=ymax;i++)
		{
			for(j=xmin;j<=xmax;j++)
			{
				int temp=((uchar*)(img->imageData + img->widthStep*i))[j];
				float temp1=((float)(i*cos(the*pi/180))-(float)(yc*cos(the*pi/180))-(float)(sin(the*pi/180)*xc)+((float)sin(the*pi/180)*j));
				
				if( (temp1<1 && temp1>-1)  && (temp >= 250) )
				{
					sig[(int)((the+90.0))]=sig[(int)((the+90.0))]+1;
				}
			}
		}
	}
	
	cout<<endl;
	
	cout<<endl<<endl;
	for( int k=0;k<=180;k++)
	{
	    fprintf(fp,"%ld\n",sig[k]);	
		//cout<<sig[k]<<" ";
	}
fclose(fp);
	return sig;
}





int mean( int *a,int lb, int ub)
{
	int i;
	int mn=0;
	for(i=lb;i<ub;i++)
	{
		mn=mn+a[i];
	}
	return (mn/(ub-lb));
}

int Color(IplImage *img,int *yc,int *xc)
{

	FILE *fp1;
	fp1=fopen("asdf1.dat","w");

	int i,j;
	int *line =new int[img->width];
	long int area=0;
	IplImage *img_hsv = 0;
	img_hsv = cvCreateImage(cvGetSize(img),8,3);
	cvCvtColor(img,img_hsv,CV_BGR2HSV);


	struct num **bmpdata1;
	bmpdata = new num*[img->height];
	bmpdata1 = new num*[img->height];


	for(i=0;i<img->width;i++)
	{
		line[i]=0;
	}


//-----------------------FINDING THE AREA, CENTROID, CLASSIFICATION OF PIXELS AS SKIN PIXELS OR NOT---------------------- 

	for(i=0;i<img->height;i++)
	{
		bmpdata[i] = new num[img->width];
		bmpdata1[i] = new num[img->width];

	for(j=0;j<img->width;j++)
	{
		bmpdata[i][j].H=((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3];
		bmpdata[i][j].S=((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3+1] ;
		bmpdata[i][j].V=((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3+2];
		if(bmpdata[i][j].H<=30 && bmpdata[i][j].S>=38)
		{	

		if(j<=xmin)
		xmin=j;

		if(j>=xmax)
		xmax=j;

		if(i>=ymax)
		ymax=i;
		
		if(i<=ymin)
		ymin=i;
		
		area++;
		*xc=*xc+j;
		*yc=*yc+i;
		line[j]+=1;
		bmpdata[i][j].S=0;
		bmpdata[i][j].V=255;
		
	
		}
		
	
		else
		{
		bmpdata[i][j].H=bmpdata[i][j].S=bmpdata[i][j].V=0;
		}
}
}

*xc/=area;
*yc/=area;

// ARM SEPARATION FINDING THRESH
//------------------------------------------------------//

for(i=0;i<img->width;i++)
{
	if (i>80 && i<(img->width-80))
	{
		if (line[i]<0.9*mean(line,i-80,i) && line[i]<mean(line,i,i+80))
		{
			thresh=i;
		}	
	}
	
}

//----------------------------------------------------------//

//-----------------------------------------------------//

// PRINTING THE NO OF SKIN PIXELS IN THE VERTICAL LINES


for(i=0;i<img->width;i++)

{
	fprintf(fp1,"%d\n",line[i]);
	//cout<<line[i]<<" ";
}


//--------------------------------------------------------//


//--------------ARM SEPARATION USING THE VALUE OF THRESH------------------------

for (i=1;i<img->height-1;i++)
{

	for (j=1;j<img->width-1;j++)
	{
	  if(bmpdata[i][j].H!=0)
		{
		if(bmpdata[i][j-1].H==0||bmpdata[i][j+1].H==0|| bmpdata[i+1][j].H==0||bmpdata[i-1][j].H==0)
		{
			bmpdata1[i][j].H=0;
			bmpdata1[i][j].S=0;
			bmpdata1[i][j].V=0;
		}
		else
		{
			bmpdata1[i][j].H+=0;
			bmpdata1[i][j].S+=0;
			bmpdata1[i][j].V+=0;
		}
}
if(j>thresh)
{	
	((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3]=0;
	((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3+1]=0;
	((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3+2]=0;
}
else
{
	((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3]=bmpdata[i][j].H;
	((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3+1]=bmpdata[i][j].S;
	((uchar*)(img_hsv->imageData + img_hsv->widthStep*i))[j*3+2]=bmpdata[i][j].V;
}
}
}
 
cvCvtColor(img_hsv,img,CV_HSV2BGR);

//------REMOVING THE HOLES AND IRREGUGALRITES----------------------//


cvErode(img,img,NULL,2);
cvDilate(img,img,NULL,2);
cvSmooth(img,img,CV_MEDIAN,5,5,0,0);


//-----------------------FREEING THE SPACE-----------------------
		for(i=0;i<img->height;i++)
		{
		delete bmpdata[i]; 
		delete bmpdata1[i]; 
		}
//-----------------------------------------------------------------

return area;
}

IplImage *rotateImage(const IplImage *src, float angleDegrees)
{
	// Create a map_matrix, where the left 2x2 matrix
	// is the transform and the right 2x1 is the dimensions
	float m[6];
	CvMat M = cvMat(2, 3, CV_32F, m);
	int w = src->width;
	int h = src->height;
	float angleRadians = angleDegrees * ((float)CV_PI / 180.0f);
	m[0] = (float)( cos(angleRadians) );
	m[1] = (float)( sin(angleRadians) );
	m[3] = -m[1];
	m[4] = m[0];
	m[2] = w*0.5f;  
	m[5] = h*0.5f;  

	// Make a spare image for the result
	CvSize sizeRotated;
	sizeRotated.width = cvRound(w);
	sizeRotated.height = cvRound(h);

	// Rotate
	IplImage *imageRotated = cvCreateImage( sizeRotated,
		src->depth, src->nChannels );

	// Transform the image
	cvGetQuadrangleSubPix( src, imageRotated, &M);

	return imageRotated;
}
//....................................................................................................
//MAIN
//MAIN
//....................................................................................................
int main(int argc,char** argv)
{
	

	

	int xc1=0,yc1=0;
	int *xc=&xc1,*yc=&yc1;

	IplImage *img;
	IplImage *img1=0;
	IplImage *img4;
	IplImage *grayImg=0,*dist=0,*edget=0,*edge=0;
	int a=0,b=0,c=0,e=0,f=0;
	int *x1=&a,*z1=&b,*y1=&c;
	int i=0,d=0,ar=0,xp=0,yp=0,ap=0;
	int D=0,AR=0;
	int area;

	th=80;D=150;AR=1500;
	CvCapture *capture1=cvCreateFileCapture("FinalVideo1.wmv");//cvCreateCameraCapture(1); //////cvCreateFileCapture("handvideo4.avi");
	//cvNamedWindow( "HAND CAPTURE1",0);
	//cvNamedWindow( "HAND CAPTURE2",0);
	//cvNamedWindow( "HAND CAPTURE3",0);
	//cvNamedWindow( "HAND CAPTURE4",0);
	//cvNamedWindow( "HAND CAPTURE5",0);


	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	//glutInitWindowPositon(50,100);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);
	glutInitWindowSize(winWidth,winHeight);
	glutCreateWindow("Hand Gesture Animation");
	init();
	initRendering();
	glutReshapeFunc(winReshapeFcn);

	img= cvQueryFrame(capture1);
	area=Color(img,yc,xc);
	edget= cvCreateImage(cvGetSize(img), IPL_DEPTH_8U,1);

	
while(1)
{	

	//char c=cvWaitKey();
	//glutMouseFunc(mouseFcn);
	
	img= cvQueryFrame(capture1);
	
	i++;
	if(!img) break;
	
	if(i>50)
	{
	if(i%1==0)
	{
		IplImage* img4=cvCloneImage(img);
		cvSaveImage("save1.jpg",img);
		//IplImage* img2=cvCloneImage(img);
		//Color1(img2,x1,y1,z1,ymax,ymin);
		
	area=Color(img,yc,xc);
		



	d=(((xc1-xp)*(xc1-xp))+((yc1-yp)*(yc1-yp)));
	ar=abs(ap-area);
	
	
	edge= cvCreateImage(cvGetSize(img), IPL_DEPTH_8U,1);
	
	cvCvtColor(img,edge,CV_BGR2GRAY);
	cvThreshold( edge, edge,100, 255, CV_THRESH_BINARY );

	double match1=cvMatchShapes(edge, edget,CV_CONTOURS_MATCH_I2);
	cout<<endl<<match1<<endl;
	//acvShowImage( "HAND CAPTURE5",img4);
	//cout<<d<<"  "<<ar<<endl;
	if(match1>0.03)
	{	
	edget=edge;	
		//cout<<d<<"  "<<ar<<endl;
	xp=xc1;yp=yc1;
	ap=area;
//................................................................................................................
	// Finding Counters
	int i,j;
	IplImage* edge2;
	IplImage* edge1;
	edge2= cvCreateImage(cvGetSize(img), IPL_DEPTH_8U,1);
	edge1= cvCreateImage(cvGetSize(img), IPL_DEPTH_8U,1);
	cvCvtColor(img,edge2,CV_BGR2GRAY);
	cvCvtColor(img,edge1,CV_BGR2GRAY);

	//edge=rotateImage(edge,90.0);

	CvMemStorage* storage = NULL;
	storage = cvCreateMemStorage(0);
	CvSeq* contours=0;
	//contours = cvCreateSeq(CV_SEQ_ELTYPE_POINT,sizeof(CvSeq*),8,storage1);
	

	CvContourScanner scanner;
	scanner = cvStartFindContours(edge2,storage,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
	contours = cvFindNextContour(scanner);
	while(contours!=NULL && (contours->total)<=100)
	{
		contours = cvFindNextContour(scanner);
	}	
	//cvSubstituteContour(scanner,NULL);
	//cout <<scanner<<"  "<<contours->total<< endl;
	//contours = cvEndFindContour();
//.........................................................................................................................
/*	CvMemStorage* storage1 = NULL;
	storage1 = cvCreateMemStorage(0);
	CvSeq* contours1=0;
	int count = cvFindContours(edge1,storage1,&contours1,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));

	cout <<count<<"          "<<contours1->total<< endl;

	cvZero(edge1);
	if( contours1 )
	cvDrawContours(edge1,contours1,cvScalarAll(255),cvScalarAll(255),100);
	*/
//.........................................................................................................................
	
	
	int* xco = new int[contours->total];
	int* yco = new int[contours->total];

	for(int i=0; i<contours->total;++i) 
		{
			CvPoint* p = (CvPoint*)cvGetSeqElem(contours,i);
			xco[i] = p->x;
			yco[i] = p->y;
		}

	for(int i=0; i<contours->total; ++i) 
		//cout<<xco[i]<<"  "<<yco[i]<<endl;
	// Drawing the counters present
	cvZero(edge2);
	if( contours )
	cvDrawContours(edge2,contours,cvScalarAll(255),cvScalarAll(255),100);
//..........................................................................................................................
	// Finding the local maxima and minima in x and y co-ordinates of boundary points
		int* mima = new int[contours->total];
		int* mxma = new int[contours->total];
		int* fmima = new int[5];
		int* fmxma = new int[5];
		int temp1 = 0,temp2 = 0,temp3=0,h=0;
		j=1;
		i=0;
		mima[j]=1;
		for(int i=6; i<(contours->total)-6;++i) 
			{
				if(xco[i]<mean(xco,i-6,i-1) && xco[i]<mean(xco,i+1,i+6))	
					{
						j++;
						mima[j]=i;
					}
				if(xco[i]>mean(xco,i-6,i-1) && xco[i]>mean(xco,i+1,i+6))	
					{
						h++;
						mxma[h]=i;
					}
			}
		fmima[1]=1;
		j=2;temp1=0;i=1;
		while(mima[j]>0)
			{ //cout<<(mima[j]-temp1)<<"   "<<(temp1-mima[j])<<endl;
				if( ((mima[j]-temp1)>10) || ((temp1-mima[j])>10) )
				{if(xco[mima[j]]<(xc1+40))
					{
						i++;
						fmima[i]=mima[j]; //cout<<fmima[i]<<endl;
							temp1=mima[j];
					}
				}
			
				 //cout<<temp1<<endl;
				j++;
			}
		
		j=1;temp1=0;i=0;
		while(mxma[j]>0)
			{ 
				if( ((mxma[j]-temp1)>10) || ((temp1-mxma[j])>10) )
				{if(xco[mxma[j]]<(xc1+40))
					{
						i++;
						fmxma[i]=mxma[j]; 
						 temp1=mxma[j];
					}
				
				}
				j++;
			}

		cvCircle(img4,cvPoint(xc1,yc1),4,CV_RGB(0,0,255),-1,8,0);
		//cout<<yc1<<endl;
//.........................................................................................................................
		// Removing extra points

//.........................................................................................................................
		
		int countmin=0;
		int countmax=0;
		j=1;
		while(fmima[j]>0)
			{
				temp1=fmima[j];
				cvCircle(img4,cvPoint(xco[temp1],yco[temp1]),4,CV_RGB(255,255,0),-1,8,0);
				//cout<<yco[temp1]<<endl;
					j++;
					countmin++;
			}
		h=1;cout<<"  "<<endl;
		while(fmxma[h]>0)
			{
				temp1=fmxma[h];
				cvCircle(img4,cvPoint(xco[temp1],yco[temp1]),4,CV_RGB(0,255,0),-1,8,0);
				//cout<<xco[temp1]<<"   "<<yco[temp1]<<endl;
					h++;
					countmax++;
			}
//.........................................................................................................................
		// Finger lengths

		double* finger = new double[5];

		j=0;
		for(i=1; i<countmin;i++)
		{	
			j++;
			temp1=fmima[i];
			temp2=fmxma[j];
			temp3=fmima[i+1];
			if (yco[temp3]>yco[temp2])
				//if((xco[temp2]-xco[temp1])<200)
			{	cvLine(img4,cvPoint(xco[temp1],yco[temp1]),cvPoint(xco[temp2],yco[temp2]),CV_RGB(255,0,0),1,8);
			finger[i]=sqrt((double)((xco[temp1]-xco[temp2])*(xco[temp1]-xco[temp2]))+(double)((yco[temp1]-yco[temp2])*(yco[temp1]-yco[temp2])));
			cout<<finger[i]<<"   ";}
			
			
			else 
				j--;
		}
		

		temp1=fmima[countmin];
		temp2=fmxma[countmax];
		cvLine(img4,cvPoint(xco[temp1],yco[temp1]),cvPoint(xco[temp2],yco[temp2]),CV_RGB(255,0,0),1,8);
		finger[i]=sqrt((double)((xco[temp1]-xco[temp2])*(xco[temp1]-xco[temp2]))+(double)((yco[temp1]-yco[temp2])*(yco[temp1]-yco[temp2])));
		cout<<finger[i]<<"   ";

		cout<<endl;

//..........................................................................................................................


	// Finding the centroid of contour
/*	int xc=0,yc=0;
	CvMoments* moments=0;
	cvMoments(edge,moments,0);
	xc =(int) ((moments->m10)/(moments->m00));
	yc = (int)((moments->m01)/(moments->m00));
	cout<<xc<<"  "<<yc<<endl;
*/
//..........................................................................................................................
/*CvPoint center;
    CvSize size;
	CvBox2D box= cvFitEllipse2(contours);
	center = cvPointFrom32f(box.center);
    size.width = cvRound(box.size.width*0.5);
    size.height = cvRound(box.size.height*0.5);
	cout<<endl<<"This is the box angle: "<<box.angle<<endl;
	//cvEllipse(edge, center, size,-box.angle, 0, 360,CV_RGB(0,0,255), 1, CV_AA, 0);
	
	
	if(box.angle<190)
	edge1=rotateImage(edge,90-(box.angle));
	if(box.angle>190)
	edge1=rotateImage(edge,270-(box.angle));
	*/
//..........................................................................................................................
		


	//	cvShowImage( "HAND CAPTURE3",edge2);
	//	cvShowImage( "HAND CAPTURE4",img1);
		cvShowImage( "HAND CAPTURE5",img4);
	


FILE *fp2;
fp2=fopen("asdf2.dat","w");

FILE *fp3;
fp3=fopen("asdf3.dat","w");

int *line1=new int[xmax-xmin];
int *line2=new int[xmax-xmin];


for(i=0;i<=xmax-xmin;i++)
{
	line1[i]=0;
	line2[i]=0;
}
		
		for(i=ymin;i<=yc1;i++)
		{
			for(j=xmin;j<=xmax;j++)
			{
				int temp=((uchar*)(edge1->imageData + edge1->widthStep*i))[j];
				if(temp==255)
				{
					line1[j-xmin]+=1;
				}
			}
		}


		for(i=yc1;i<=ymax;i++)
		{
			for(j=xmin;j<=xmax;j++)
			{
				int temp=((uchar*)(edge1->imageData + edge1->widthStep*i))[j];
				if(temp==255)
				{
					line2[j-xmin]+=1;
				}
			}
		}


for(i=0;i<xmax-xmin;i++)

{
	fprintf(fp2,"%d\n",line1[i]);
	fprintf(fp3,"%d\n",line2[i]);
	
}

fclose(fp3);
fclose(fp2);

//cout<<"This is the threshold value"<<thresh<<" "<<xmin<<endl;

int det_oru[20];
int det_ord[20];

int ymean_d=0;
int ymean_u=0;
int k=0;
int xmean=0;

/*


for(j=thresh-19;j<=thresh;j++)
{
	
	for(i=ymin;i<=ymax;i++)
	{
		int temp=((uchar*)(edge1->imageData + edge1->widthStep*i))[j];
		if(temp==255)
		{
		ymean_u=ymean_u+i;
		det_oru[k]=i;
		k++;
		break;
		}
	}

	xmean=xmean+j;
}

det_oru[k]=-1;
ymean_u/=20;
xmean/=20;

k=0;
for(j=thresh-19;j<=thresh;j++)
{
	
	for(i=ymax;i>=ymin;i--)
	{
		int temp=((uchar*)(edge1->imageData + edge1->widthStep*i))[j];
		if(temp==255)
		{
		ymean_d=ymean_d+i;
		det_ord[k]=i;
		k++;
		break;
		}
	}
}

ymean_d/=20;
det_ord[k]=-1;

float slope_u=0.0,slope_d=0.0;
float den=0.0;

for(i=0;i<20;i++)
{
	slope_u=slope_u+((det_oru[i]-ymean_u)*(thresh-19+i-xmean));
	slope_d=slope_d+((det_ord[i]-ymean_d)*(thresh-19+i-xmean));
	den=den+((thresh-19+i-xmean)*(thresh-19+i-xmean));
}

slope_u/=den;
slope_d/=den;
cout<<endl<<"This is the upper slope"<<slope_u<<" "<<"This is the lower slope"<<slope_d<<" HI" <<endl;
*/


long int *sig=RadialSignature(edge1,xc1+70,yc1);
long int *sig1= new long int [181];
sig1[0]=sig[0];
sig1[180]=sig[180];

for(i=1;i<180;i++)
{
	sig1[i]=(sig[i-1]+sig[i+1])/2;
}

int *max1=findlocmaxmin(sig1);


int temp=0;

i=0;
while(max1[i]!=-1)
{
cout<<max1[i]<<" ";
i++;
}
cout<<endl;

i=0;
while(max1[i]!=-1)
{
	
	if(sig1[max1[i]]>temp)
	{temp=sig1[max1[i]];}

	i++;
}

int length_max1=i;
i=0;

while(max1[i]!=-1)
{
	if(sig1[max1[i]]<0.7*temp)
	{max1[i]=-1;}
	if(max1[i]>=68 && max1[i]<=110 && sig1[max1[i]]<0.8*temp)
	{ 
	max1[i]=-1;
	}
	if(max1[i]==(max1[i+1]-1) || max1[i]==(max1[i+1]-2))
	{max1[i]=-1;}

	i++;
}

k=0;
int *max2=new int[length_max1];
for(i=0;i<=length_max1;i++)
{
	if(max1[i]==-1)
	continue;

	else
	{
		max2[k]=max1[i];
		k++;
		cout<<max1[i]<<" ";
	}
}
max2[k]=-1;
cout<<endl;

int *ar=new int[5];
int inf=0,tf=0,mf=0,rf=0,pf=0;
i=0;

for(i=0;i<=4;i++)
{
	ar[i]=0;
}
i=0;
while(max2[i]!=-1)
{
	
		if(max2[i]==-1)
		{
			i++;
			continue;
		}

		if(max2[i]<60)
		{
			if(ar[0]==0)
				ar[0]=1;
			else
			ar[1]=1;
			
		}

		else if(max2[i]>=68 && max2[i]<85)
		{
			if(ar[1]==1 && max2[i]>74)
				ar[2]+=1;
			else
				ar[1]+=1;
		
		}
		else if(max2[i]>=85 && max2[i]<100 && mf==0)
		{
			if(ar[2]==1 && max2[i]>87)
				ar[3]+=1;
			else
				ar[2]+=1;
		
		}
		else if(max2[i]>=100 && max2[i]<108 && rf==0)
		{
			if(ar[3]==1 && max2[i]>102)
				ar[4]+=1;
			else
				ar[3]+=1;
				
		}
			
		else if (max2[i]>=108 && pf==0)
		{
			if(ar[4]==0)
				ar[4]=1;
			else
			ar[3]=+1;
			
		}
				
		i++;
}


for(i=0;i<=4;i++)
{
	cout<<ar[i]<<" ";
}
cout<<endl;


	if(ar[0]==0)
	{
		angles2[12]=90;
		angles2[13]=90;
	}

	else
	{
		angles2[12]=0.0;
		angles2[13]=0.0;
	}

	if(ar[1]==0)
	{
		angles2[9]=180;
		angles2[10]=270;
		angles2[11]=90;
	}

	else
	{
		angles2[9]=0.0;
		angles2[10]=0.0;
		angles2[11]=0.0;
	}

		if(ar[2]==0)
	{
		angles2[6]=180;
		angles2[7]=270;
		angles2[8]=90;
	}

	else
	{	
		angles2[6]=0.0;
		angles2[7]=0.0;
		angles2[8]=0.0;
	}

		if(ar[3]==0)
	{
		angles2[3]=180;
		angles2[4]=270;
		angles2[5]=90;
	}

	else
	{
		angles2[3]=0.0;
		angles2[4]=0.0;
		angles2[5]=0.0;
	}

		if(ar[4]==0)
	{
		angles2[0]=180;
		angles2[1]=270;
		angles2[2]=90;
	}

	else
	{
		angles2[0]=0.0;
		angles2[1]=0.0;
		angles2[2]=0.0;
	}




	



while(temporary!=0)
{
glutDisplayFunc(wireQuadSurfs);
glutMainLoopEvent();
animate();
}
temporary=1;

for(i=0;i<14;i++)
{
angles1[i]=angles2[i];
}


}


char c=cvWaitKey(1);
if(c=='a') break;
}//if(i%1) ending 


}//if(i>50) ending


}//while ENDING
cvReleaseCapture(&capture1);









cvDestroyWindow( "HAND CAPTURE1" );
cvDestroyWindow( "HAND CAPTURE2" );
cvDestroyWindow( "HAND CAPTURE3" );
cvDestroyWindow( "HAND CAPTURE4" );
cvDestroyWindow( "HAND CAPTURE5" );


return 0;
}


