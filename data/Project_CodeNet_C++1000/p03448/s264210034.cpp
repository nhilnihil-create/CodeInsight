#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,n,i,j,k,s=0;
	cin>>a>>b>>c>>n;
	for(i=0;i<=a;i++)
	{
		if(500*i>n) a=i;
		for(j=0;j<=b;j++)
		{
			if(100*j>n) b=j;
			for(k=0;k<=c;k++)
			{
				if(500*i+100*j+50*k==n) s++;
			}
		}
	}
	cout<<s;
	return 0;
 } 
