
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define fo(i,n)         for(i=0;i<n;i++)
#define Fo(i,k,n)       for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int N = 3e5, M = N;
//=======================

vi g[N];

void solve() {
	int i, j, n, m;
	int k;
	cin >> n >> k;
	int a[n];
	fo(i, n) cin >> a[i];
	int dp[2][k + 1];
	//dp[studenet][candies]
	int cur = 0;
	int prev = 1;
	fo(i, k + 1) {
		dp[cur][i] = 0;
	}
	fo(j, 2) {
		dp[j][0] = 1;
	}
	std::vector<int> prefix(k + 1);
	Fo(i, 1, n + 1) {
		cur = 1 ^ cur;
		prev = 1 ^ prev;
		Fo(j, 0, k + 1) {
			prefix[j] = dp[prev][j] % mod;
			if (j) prefix[j] = (prefix[j] % mod + prefix[j - 1] % mod) % mod;
		}
		Fo(j, 1, k + 1) {
			if (j <= a[i - 1]) {
				dp[cur][j] = prefix[j] % mod;
			}
			else {
				int non_cnting = j - a[i - 1] - 1;
				dp[cur][j] = ( prefix[j] % mod - prefix[non_cnting] % mod + mod) % mod;
			}
		}
		prefix.clear();
	}

	cout << dp[cur][k];
}

int32_t main()
{
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}

