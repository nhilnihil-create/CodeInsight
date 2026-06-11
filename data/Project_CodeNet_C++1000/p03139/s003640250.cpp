#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int ansa,ansb;
	ansa=min(a,b);
	if (a+b>n) ansb=a+b-n;
	else ansb=0;
	cout<<ansa<<" "<<ansb;
	return 0;
} 