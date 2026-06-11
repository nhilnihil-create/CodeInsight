#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,p=100000000;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b,c,d,e,v,w,x,y,z,s=0;
    a=i/10000;
    b=i/1000-10*a;
    c=i/100-100*a-10*b;
    d=i/10-1000*a-100*b-10*c;
    e=i-10000*a-1000*b-100*c-10*d;
    v=(n-i)/10000;
    w=(n-i)/1000-10*v;
    x=(n-i)/100-100*v-10*w;
    y=(n-i)/10-1000*v-100*w-10*x;
    z=(n-i)-10000*v-1000*w-100*x-10*y;
    s=a+b+c+d+e+v+w+x+y+z;
    if(s<=p){
      p=s;
    }
  }
  cout<<p<<endl;
}
      
  
  