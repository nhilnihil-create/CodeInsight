#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if (a+b==15) cout<<"+"<<endl;
	else if (a*b==15) cout<<"*"<<endl;
	else cout<<"x"<<endl;
	return 0;
}