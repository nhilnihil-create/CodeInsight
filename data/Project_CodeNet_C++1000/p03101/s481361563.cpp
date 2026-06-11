#include<iostream>
using namespace std;
int main(){
   int h,w,x,y;
   cin>>h>>w>>x>>y;
   int max1 = ((x*w)+(y*h))-(x*y);
   int dif = (h*w)-(max1);
   cout<<dif<<endl;
}