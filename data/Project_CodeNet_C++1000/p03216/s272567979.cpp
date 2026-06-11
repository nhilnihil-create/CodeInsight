#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,q;
	string s;
	cin>>n>>s>>q;
	for (int i = 0; i < q; ++i)
	{
		int k;
		cin>>k;
		long long d=0LL,m=0LL,cnt=0LL,ans=0LL;
		for (int j = 0; j < k; ++j)
		{
			if (s[j]=='D')
			{
				++d;
			}
			else if (s[j]=='M')
			{
				++m;
				cnt+=d;
			}
			else if (s[j]=='C')
			{
				ans+=cnt;
			}
		}
		for (int j = k; j < n; ++j)
		{
			if (s[j-k]=='D')
			{
				--d;
				cnt-=m;
			}
			else if (s[j-k]=='M')
			{
				--m;
			}
			if (s[j]=='D')
			{
				++d;
			}
			else if (s[j]=='M')
			{
				++m;
				cnt+=d;
			}
			else if (s[j]=='C')
			{
				ans+=cnt;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
