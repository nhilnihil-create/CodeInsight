#include<iostream>
using namespace std;
int main()
{
int A,B,C,min1,min2,max1,area;
cin>>A>>B>>C;
if(A<=B)
{min1=A;
max1=B;}
else{min1=B;
    max1=A;}
  if (max1<=C)
  {min2=max1;}
  else{min2=C;}
 area=0.5*min1*min2;
  cout<<area;

return 0;





}