
#include<iostream>
using namespace std;

int main (void){
  int n,w,start,goal,x,y,gosen,man,sen;
//*
  cin>>n>>w;;

  start=1000*n;
  goal=(w-start)/1000;
 // cout<<"goal:"<<goal<<endl;
  goal=goal+4;
  x=goal/9;
  x*=2;
  if(goal%9<=4)
  {
    y=goal%9;y*=2;
  }
  else
  {
    y=goal%9-4;
    y*=2;
    y--;
    x++;
  }

//cout<<"x="<<x<<",y="<<y<<endl;
  if(x+y<8||y-x<-2*n+8)
  {
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
  }
  else
  { 
    y=8-y;
    man=(x-y)/2;
    gosen=y;
    sen=n-man-gosen;
    cout<<man<<" "<<gosen<<" "<<sen<<endl;
  }
 
}

