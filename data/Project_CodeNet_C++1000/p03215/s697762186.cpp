#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	long long a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	multiset<long long> b;
	for (int i = 0; i < n; ++i)
	{
		long long s=0LL;
		for (int j = i; j < n; ++j)
		{
			s+=a[j];
			b.insert(s);
		}
	}
	long long ans=0LL;
	for (int i = 50; i >= 0; --i)
	 {
	 	int cnt=0;
	 	for (auto v:b)
	 	{
	 		if ((v&(1LL<<i))>0)
	 		{
	 			++cnt;
	 		}
	 	}
	 	if (cnt>=k)
	 	{
	 		ans+=(1LL<<i);
	 		for (auto itr = b.begin(); itr != b.end();)
	 		{
	 			if (((*itr)&(1LL<<i))==0LL)
	 			{
	 				itr=b.erase(itr);
	 			}
	 			else
	 			{
	 				++itr;
	 			}
	 		}
	 	}
	} 
	cout<<ans<<endl;
	return 0;
}
