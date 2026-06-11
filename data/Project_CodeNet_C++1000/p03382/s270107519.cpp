#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	set<long long> a;
	long long b,ma=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>b;
		a.insert(b);
		ma=max(ma,b);
	}
	if (n==2)
	{
		cout<<ma<<" "<<*a.begin()<<endl;
		return 0;
	}
	auto i=a.lower_bound(ma/2LL+1LL);
	if (*i==ma)
	{
		--i;
	}
	long long ans=*i;
	--i;
	if (abs(ma/2LL-ans)>abs(ma/2LL-*i))
	{
		ans=*i;
	}
	cout<<ma<<" "<<ans<<endl;
	return 0;
}
