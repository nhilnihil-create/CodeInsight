#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
map <pair<string,string>,int> mp;
int main()
{
	int n;
	long long ans=0;
	string s,a,b;
	cin>>n;
	cin>>s;
	mp.clear();
	for(int i=0;i<(1<<n);i++)
	{
		a="";
		b="";
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				a+=s[j];
			else
				b+=s[j];
		mp[make_pair(a,b)]++;
	}
	for(int i=0;i<(1<<n);i++)
	{
		a="";
		b="";
		for(int j=1;j<=n;j++)
			if(i&(1<<j))
				a+=s[n+n-j];
			else
				b+=s[n+n-j];
		ans+=mp[make_pair(a,b)];
	}
	printf("%lld",ans);
	return 0;
}