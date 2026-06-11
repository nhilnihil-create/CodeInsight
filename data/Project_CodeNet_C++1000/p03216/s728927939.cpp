#include<bits/stdc++.h>
using namespace std;
int n,q;
string s;
vector<int>x;
int main()
{
	cin>>n>>s>>q;
	for(int i=0;i<q;i++)
	{
		int a;
		cin>>a;
		x.push_back(a-1);
	}
	for(int i=0;i<x.size();i++)
	{
		int l=x[i];
		long long ans=0,now=0,add=0;
		queue<long long>q;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='D')
			{
				q.push(add);
			}
			if(s[i]=='M')
			{
				now+=q.size();
				add++;
			}
			if(s[i]=='C')
			{
				ans+=now;
			}
			if(i>=l)
			{
				long long k=i-l;
				if(s[k]=='D')
				{
					now-=(add-q.front());
					q.pop();
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}