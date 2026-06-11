#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main() 
{

int a,b;
cin>>a>>b;
int x;
if(a>b)
x=2*a-1;
else if(b>a)
x=2*b-1;
else if(a==b)
x=2*a;
cout<<x;
return 0;
}