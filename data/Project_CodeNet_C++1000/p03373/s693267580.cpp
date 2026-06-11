#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
 int wari(int a,int b) {
   if(a%b==0)
     return a/b;
   else
     return a/b+1;
 }
 int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
 }
 int souwa(int a){
  return a*(a+1)/2;
 }
 int lcm(int a,int b){
  int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return d*e/f;
    }
  int gcm(int a,int b){
      int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return f;
  }
signed main(){
  int a,b,c,d,e,f=0;
  cin>>a>>b>>c>>d>>e;
  if(a+b<=2*c)
    f+=a*d+b*e;
  else{
    f+=2*c*min(d,e);
    if(d<e)
      swap(a,b),swap(d,e);
    if(a>2*c)
      f+=2*c*(d-e);
    else
      f+=a*(d-e);
  }
  cout<<f<<endl;
}