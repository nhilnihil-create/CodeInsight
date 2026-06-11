#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
 
const int lim = 1e6 + 5;
const int Inf = 1000000007;
const long long mod = 1000000007;//998244353;
const double Pi = acos(-1);
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int p[200005];
int pos[200005];
int dp[200005];

int main()
{
//	Fastio();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i];
		pos[p[i]] = i;
	}
	dp[n] = 1;
	for(int i = n - 1; i >= 1; i--)
	{
		if(pos[i] < pos[i + 1])
		{
			dp[i] = dp[i + 1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
	}
	int m = 0;
	for(int i = 1; i <= n; i++)
	{
		m = max(m, dp[i]);
	}
	cout << n - m;
}