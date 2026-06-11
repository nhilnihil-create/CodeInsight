#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n),sum(n+1);
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i =0;i<n;i++)
	{
		sum[i+1] += sum[i] + a[i];
	}
	sort(sum.begin(),sum.end());
	sum.push_back(LLONG_MAX);
	ll l = 1;
	ll ans = 0;
	for(int i = 0;i<n+1;i++)
	{
		if(sum[i]==sum[i+1])
		{
			l++;
		}
		else
		{
			ans += l*(l-1)/2;
			l = 1;
		}
	}
	cout<<ans<<endl;
}