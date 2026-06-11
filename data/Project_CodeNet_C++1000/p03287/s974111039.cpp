#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> A(n);
	for(int i = 0;i<n;++i)cin >> A[i];

	vector<ll> sum(n+1);
	for(int i =0;i<n;i++)
	{
		A[i]%=m;
		sum[i+1] +=sum[i]+ A[i];
		sum[i+1]%=m;
	}
	sort(sum.begin(),sum.end());
	//for(auto i:sum)cout<<i<<' ';cout<<endl;
	ll ans = 0;
	ll l = 1;
	sum.push_back(-1);
	for(int i = 0;i<n+1;i++)
	{
		if(sum[i]==sum[i+1])
		{
			l++;
		}
		else
		{
			ans += l*(l-1)/2;
			l=1;
			//cout<<ans<<endl;
		}
	}
	cout<<ans<<endl;
}