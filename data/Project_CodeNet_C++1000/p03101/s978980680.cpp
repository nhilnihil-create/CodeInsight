#include<iostream>
using namespace std;

int main() 
{
   int H,W,h,w;
   cin>>H>>W;
   cin>>h>>w;
   
   H=H-h;
   W=W-w;
   cout<<H*W;
   return 0;
   
}