#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main (void)
{
  int s,a,b;
  bool af=0,bf=0;
  cin>>s;
  //cout<<s<<endl;
  a=s%100;
  b=s/100;
  if(a>0&&a<13){af=1;}
  if(b>0&&b<13){bf=1;}
  if(af==1&&bf==1){cout<<"AMBIGUOUS"<<endl;}
  else if(af==1){cout<<"YYMM"<<endl;}
  else if(bf==1){cout<<"MMYY"<<endl;}
  else{cout<<"NA"<<endl;}
}