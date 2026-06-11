#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a*b==15) cout<<"*"<<endl;
	if(a+b==15) cout<<"+"<<endl;
	if(a*b!=15&&a+b!=15) cout<<"x"<<endl;
	return 0;
}