#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
		
	int n, k;
	cin >> n >> k;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vi dp(k + 1);
	dp[0] = 0;
	for(int i = 1; i <= k; i++) {
		for(int j:a) if(i - j >= 0 && dp[i - j] == 0) dp[i] = 1;
	}
	cout << (dp[k] ? "First" : "Second") << endl;

}

