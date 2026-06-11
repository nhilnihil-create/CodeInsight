#include<iostream>
using namespace std;
int main ()
{
    int H,W,h,w,x,y;
    cin>>H>>W>>h>>w;
   x=(H*W)-(h*W);
   y=(H-h)*w;
   cout<<x-y<<endl;
   return 0;
}
