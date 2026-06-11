#include<iostream>
using namespace std;
int main(){
int a,b,c,n,s=0;
cin>>a>>b>>c>>n;
for(int i=0;i<=a;i++)
for(int j=0;j<=b;j++)
for(int k=0;k<=c;k++)
if(i*500+j*100+k*50==n)
s++;
cout<<s;
}
