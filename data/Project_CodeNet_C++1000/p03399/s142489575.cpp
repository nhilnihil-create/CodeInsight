#include<iostream>
 using namespace std ;
 int main()
{
 int A, B, C, D, x, y, z, k;
 cin>>A;
 cin>>B;
 cin>>C;
 cin>>D;
x=(A+C);
y=(A+D);
z=(B+C);
k=(B+D);
if (x<=y&&x<=z&&x<=k)
{
  cout<<x<<endl;
}
if  (y<=k&&y<x&&y<=z)
{
  cout<<y<<endl;
}
if (z<y&&z<x&&z<=k)
{
  cout<<z<<endl;
}
if (k<y&&k<z&&k<x)
{
  cout<<k<<endl;
}
}