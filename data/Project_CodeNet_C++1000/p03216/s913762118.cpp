#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int q;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		long long ret=0,dm=0;
		int d=0,m=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='C')
			{
				ret+=dm;
			}
			else if(s[i]=='D')
			{
				d++;
			}
			else if(s[i]=='M')
			{
				dm+=d;
				m++;
			}
			if(i>=k-1)
			{
				int p=i-k+1;
				if(s[p]=='D')
				{
					dm-=m;
					d--;
				}
				else if(s[p]=='M')
				{
					m--;
				}
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}