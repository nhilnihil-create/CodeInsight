#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fio ios_base::sync_with_stdio(false)
#define pdl cout << "*" << endl
#define MOD 1000000007
#define INF 1000000000
#define INFLL 1000000000000000000ll
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define long int64_t
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef priority_queue<pii, vector<pii>, greater<pii>> min_pq;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(0, INF<<1);
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1){ cerr << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{ const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma+1, args...); }

const int N = 5001;

long dp[N];
int b[N];

int main()
{
	fio;
	int n;
	long A, B;
	cin >> n >> A >> B;
	for(int i=1; i<=n; i++)
		cin >> b[i];
	long ans = INFLL;
	for(int i=1; i<=n; i++)
	{
		dp[i] = INFLL;
		int c = 0;
		for(int j=i-1; j>=0; j--)
		{
			if(b[i] > b[j])
				dp[i] = min(dp[i], dp[j] + c * A + (i - j - 1 - c) * B);
			else
				c++;
		}
		ans = min(ans, dp[i] + (n - i) * B);
	}
	cout << ans << endl;
	return 0;
}