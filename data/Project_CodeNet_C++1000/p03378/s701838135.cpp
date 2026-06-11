#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	int i,a[m],u=0,v=0;
	for(i=0;i<m;i++)
	{
		cin>>a[i];
		if(a[i]>x)
		{
			u++;
		}
		else
		{
			v++;
		}
	}
	if(v>u)
	{
		cout<<u;
	}
	else
	{
		cout<<v;
	}
		
}