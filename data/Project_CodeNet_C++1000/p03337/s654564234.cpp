#include<iostream>
 using namespace std ;
 int main()
{
 int A,B,m,n,c;
 cin>>A>>B;
 c=A+B;
 m=A*B;
 n=A-B;
 if (n>m && n>c)
 {cout << n;}
 else if (m>n && m>c)
 {cout<< m ;}
else 
{cout << c; }
}