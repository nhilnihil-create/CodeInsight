#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	cout<<min(a,b)<<" ";
	int t=a+b-n;
	if(t<=0)
			cout<<"0";
		
	else
		cout<<t;
	return 0;
}