#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
void add(int &a, int b)
{
	a+=b;
	while(a>mod)
		a-=mod;
	while(a<0)
		a+=mod;
}

signed main()
{
	int n,k;
	cin>>n>>k;
	vector<int> dp(k+1, 0);

	dp[0]=1;
	for(int child=1; child<=n; ++child)
	{
		int up;
		cin>>up;
		vector<int> poschange(k+1), negchange(k+1);
		for(int used=k; used>=0; --used)
			{
				int l=used+1, r=used+min(up, k-used);
				if(l<=k)
					add(poschange[l], dp[used]);
				if(r+1<=k)
					add(negchange[r+1], dp[used]);

			}
		int ps=0;
		for(int i=0; i<=k; ++i)
		{
			add(ps, poschange[i]);
			add(ps, -negchange[i]);
			add(dp[i], ps);
		}
	}
	// for(int i=0; i<=k; ++i)
	// 	cout<<i<<"->"<<dp[i]<<endl;
	cout<<dp[k];
	return 0;
}