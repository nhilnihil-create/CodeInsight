#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
int n,a,b;
cin>>n>>a>>b;
int a1=n*a;
if(a1<=b)
cout<<a1;
else
cout<<b;
return 0;  
}