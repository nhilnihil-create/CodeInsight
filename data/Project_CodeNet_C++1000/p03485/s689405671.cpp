#include<iostream>
using namespace std;
int main()
{
   int a,b,s;
   cin>>a>>b;
   s=a+b;
   if(s%2==0){cout<<s/2;}
   else{cout<<(s/2)+1;}
}