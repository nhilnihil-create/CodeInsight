#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int i,j,n,a,b,d=1,c,z=0;
	cin>>n>>a>>b;
	string x="1";
	d=stoi(x);
	for(i=1;i<=n;i++)
	{
		int k=0,s=0;
		
		x=to_string(d);
		c=x.size();
		for(j=0;j<c;j++)
		{
			k=x[j]-'0';
			s=s+k;
			
		}
		if(s>=a && s<=b)
		{
			z=z+d;	
		}
		d=stoi(x)+1;
	}
	cout<<z<<endl;
}