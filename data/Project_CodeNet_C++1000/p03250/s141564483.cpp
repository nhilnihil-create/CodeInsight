#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a>=b && a>=c){cout<<a*10+b+c<<endl;}
	else if(b>=c && b>=a){cout<<b*10+a+c<<endl;}
	else if(c>=b && c>=a){cout<<c*10+a+b<<endl;}
}