#include<bits/stdc++.h>
using namespace std;
int main()
{
int h,w;
  int a,b;
  cin>>h>>w>>a>>b;
  if(h==a && w==b){
  cout<<"0";
  return 0;}
  cout<<(h*w)-(a*w+b*h-a*b);
}