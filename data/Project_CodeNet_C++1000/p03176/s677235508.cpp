#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define int long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define MAXN 1000001

int a[MAXN], b[MAXN];
int dp[MAXN];
int fen[MAXN];
int n;
void update(int i, int add)
{
	while (i <= n)
	{
		fen[i] = max(fen[i], add);
		i = i + (i & (-i));
	}
}

int query(int i)
{
	int s = 0;
	while (i > 0)
	{
		s = max(s, fen[i]);
		i = i - (i & (-i));
	}
	return s;
}
int32_t main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	for (int j = 0; j < n; j++) {
		cin >> b[j];
	}

	for (int i = 0; i < n; i++)
	{
		dp[i] = query(a[i] - 1) + b[i];
		update(a[i], dp[i]);
	}
	cout << *max_element(dp, dp + n);

}
