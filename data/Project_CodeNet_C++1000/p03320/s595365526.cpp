#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int k;
	cin>>k;
	set<pair<double,long long>> ans;
	for (int i = 1; i < 10000; ++i)
	{
		long long now=(long long)i,s=0LL;
		while (now>0LL)
		{
			s+=now%10LL;
			now/=10LL;
		}
		ans.insert({(double)i/s,i});
	}
	long long r=9LL;
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 10000; ++j)
		{
			long long now1=(long long)j*(r+1LL)+r,now2=now1,s=0LL;
			while (now1>0LL)
			{
				s+=now1%10LL;
				now1/=10LL;
			}
			ans.insert({(double)now2/s,now2});
		}
		r*=10LL;
		r+=9LL;
	}
	long long tmp=0LL;
	for (auto i = ans.begin(); i != ans.end(); ++i)
	{
		auto p=*i;
		if (p.second>tmp)
		{
			tmp=p.second;
			cout<<p.second<<endl;
			--k;
			if (k==0)
			{
				return 0;
			}
		}
	}
	return 0;
}