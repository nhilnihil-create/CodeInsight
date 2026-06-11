#include<iostream>
using namespace std;

long long n,q,i,j,k,d,m,d_m,ans;
char s[1000005];
	
int main()
{
	cin>>n>>s>>q;
	for(i=0; i<q; i++)
	{
		cin>>k;
		d=m=d_m=ans=0;
		for(j=0; j<n; j++)
		{
			if(j>=k)
			{
				if(s[j-k]=='D')
				{
					d--;
					d_m-=m;
				}
				if(s[j-k]=='M')
					m--;
			}
			if(s[j]=='D')
				d++;
			if(s[j]=='M')
			{
				m++;
				d_m+=d;
			}
			if(s[j]=='C')
				ans+=d_m;
		}
		cout<<ans<<endl;
	}
	return 0;
}