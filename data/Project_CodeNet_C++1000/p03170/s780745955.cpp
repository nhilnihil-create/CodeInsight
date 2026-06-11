#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;
const int maxn = 100005;
int dp[maxn];
vector<int>v;
int solve(int x) {
	if (~dp[x]) {
		return dp[x];
	}
	int mi = 1;
	for (auto &i : v) {
		if (i > x) {
			break;
		}
		mi = min(mi, solve(x - i));
	}
	return dp[x] = mi ^ 1;
}
void go() {
	int n, k;
	cin >> n >> k;
	f(n) {
		int x;
		cin >> x;
		v.pb(x);
	}
	memset(dp, -1, sizeof(dp));
	cout << (solve(k) ? "First" : "Second") << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}