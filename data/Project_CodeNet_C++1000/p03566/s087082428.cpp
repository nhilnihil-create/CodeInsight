#include<iostream>
using namespace std;
#define df 0

double f(int vl,int vr,int vm,int t){
  int M=max(vl,vr),d=2*M-vl-vr,r=t-d;
  double sum=M*t-d*d*0.5+r*r*0.25, h=r*0.5+M-vm;
  if(h<0)h=0;
  sum-=h*h;
  if(df)printf("%lf\n",sum);
  return sum;
}

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >>n;
  int t[n],v[n];
  for(int& x:t) cin >>x;
  for(int& x:v) cin >>x;
  int w[n+1];
  w[0]=w[n]=0;
  for(int i=0;i<n-1;i++){
    w[i+1]=min(v[i],v[i+1]);
  }
  if(df){
    for(int x: w)printf("%d ",x);
    printf("\n");
  }
  int temp=0;
  for(int i=0;i<n;i++){
    temp+=t[i];
    w[i+1]=min(w[i+1],temp);
    temp=w[i+1];
  }
  if(df){
    for(int x: w)printf("%d ",x);
    printf("\n");
  }
  temp=0;
  for(int i=n-1;i>=0;i--){
    temp+=t[i];
    if(df)printf("min(%d,%d)",temp,w[i]);
    w[i]=min(w[i],temp);
    temp=w[i];
  }
  if(df){
    printf("t[n-1]=%d,w[n]=%d\n",t[n-1],w[n]);
    for(int x: w)printf("%d ",x);
    printf("\n");
  }

  double sum=0;
  for(int i=0;i<n;i++){
    sum+=f(w[i],w[i+1],v[i],t[i]);
  }
  printf("%lf",sum);
}

/// confirm df==0 ///