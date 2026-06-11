#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

const long long INF = 1e18; 
const long long mod = 998244353;//200003;786433;1e9 + 7;
const double Pi = acos(-1);
  
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, ans = 0;
int a[1 << 18];
multiset <int> DP[1 << 18]; 

signed main()
{
	cin >> n;
	for(int i = 0; i < 1 << n; i++)
	{
		cin >> a[i];
		DP[i].insert(a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 1 << n; j++)
		{
			if(j & (1 << i))
			{
				continue;
			}
			for(auto x : DP[j])
			{
				DP[j ^ (1 << i)].insert(x);
			}
			while(DP[j ^ (1 << i)].size() > 2)
			{
				DP[j ^ (1 << i)].erase(DP[j ^ (1 << i)].begin());
			}
		}
	}
	for(int i = 1; i < 1 << n; i++)
	{
		int sum = 0;
		if(DP[i].size() == 2)
		{
			for(auto x : DP[i])
			{
				sum += x;
			}
		}
		ans = max(ans, sum);
		cout << ans << '\n';
	}
}