#include<iostream>
using namespace std;
int main()
{  int a,b;
 cin>>a>>b;
 if(a==0)
 {  if(b!=100)
     cout<<b;
   else
      cout<<101;
 }
else if(a==1)
{  if(b!=100)
    cout<<b*100;
  else
     cout<<101*100;
}   
else
{ if(b!=100)
    cout<<b*100*100;
  else
      cout<<101*100*100;
}  
}