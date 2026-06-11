#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c[3];
	cin>>a>>b;
	c[0]=a+b;
	c[1]=a-b;
	c[2]=a*b;
	cout<<max(c[0],max(c[1],c[2]))<<endl;
	return 0;
}