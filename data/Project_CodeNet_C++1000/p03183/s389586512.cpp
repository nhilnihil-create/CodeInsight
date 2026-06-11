#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string.h>
#include <map>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>
#include <math.h>
#include <time.h>
#include <assert.h>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <ll,ll>
#define N 100005
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;

struct node
{
	int wt, str,  val;
}s[1005];

bool cmp(node x, node y)
{
	return (x.wt + x.str < y.wt + y.str);
}
ll dp[N], ans = 0;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i].wt >> s[i].str >> s[i].val;
	}
	sort(s, s + n, cmp);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		for (int w = (s[i].str + s[i].wt); w >= 1; --w)
		{
			if(s[i].wt <= w)
				dp[w] = max(dp[w], dp[w - s[i].wt] + s[i].val);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
