#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A, B, c, d, e;
	cin>>A>>B;
	
	c = A+B;
	d = A-B;
	e = A*B;
	
	if (c>d && c>e)
	{
	    cout<<c<<'\n';
	}
	
	else if (d>c && d>e)
	{
	    cout<<d<<'\n';
	}
	
	else if (e>c && e>d)
	{
	    cout<<e<<'\n';
	}
	
	else if (A==0 && B==0)
	{
	    cout<<"0"<<'\n';
	}
	
	else if (A>0 && B==0)
	{
	    cout<<A<<'\n';
	}
	
	else if (A==0 && B>0)
	{
	    cout<<B<<'\n';
	}
	
	return 0;
}