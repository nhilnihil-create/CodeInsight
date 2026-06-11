#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,n;
	cin>>a>>n;;
	if(a+n==15)
	{
		cout<<"+"<<endl;
		return 0;
	}
	if(a*n==15)
	{
		cout<<"*"<<endl;
		return 0;
	}
	cout<<"x"<<endl;
	return 0;
}