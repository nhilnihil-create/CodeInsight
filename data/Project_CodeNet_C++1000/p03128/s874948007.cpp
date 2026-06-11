#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1 << 30;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

int main()
{	
	int num[10] = {0,2,5,5,4,5,6,3,7,6};

	int n, m;
	cin >> n >> m;

	vector<int> v(m);
	rep(i, m)
	{
		cin >> v[i];
	}

	//dp[i]:=i本のマッチをちょうど使い切って作ることのできる整数の桁数の最大値
	vector<ll> dp(n + 1);
	dp[0] = 0;

	reple(i, 1, n)
	{
		dp[i] = -INF;
		for(auto j : v)
		{
			int c = num[j];
			if (i - c >= 0)
			{
				dp[i] = max(dp[i], dp[i - c] + 1);
			}
		}
	}


	//数値の復元
	//最上位の桁から求めていく。
	//数字nが使用できる条件は、dp[i] = dp[i - num[n]] + 1
	sort(all(v), greater<int>());
	int d = n;
	while (d > 0)
	{
		for (auto j : v)
		{
			int tmp = d - num[j];
			if (tmp < 0) continue;
			if (dp[d] == dp[tmp] + 1)
			{
				cout << j;
				d = tmp;
				break;
			}
		}
	}

	return 0;
}