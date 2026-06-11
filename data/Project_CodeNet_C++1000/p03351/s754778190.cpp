#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int a,b,c,d;
int main()
{
	cin>>a>>b>>c>>d;
	if((abs(a-b)<=d&&abs(b-c)<=d)||(abs(a-c)<=d))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}