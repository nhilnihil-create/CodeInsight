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
int dp[21][1<<21];
void go() {
	int n;
	cin >> n;
	int m[21][21] = {};
	f(n) {
		fr(j,0,n) {
			cin >> m[i][j];
		}
	}	
	f(n) {
		if (m[0][i]) {
			dp[0][1<<i] = 1;
		}
	}
	f1(n-1) {
		fr(j,0,1<<n) {
			if (__builtin_popcount(j) != i + 1) {
				continue;
			}
			fr(k,0,n) {
				if (m[i][k] &&(j & (1<<k))) {
					dp[i][j] += dp[i - 1][j ^ (1<<k)];
					dp[i][j] %= mod;
				}
			}
		}
	}
	cout << dp[n-1][(1<<n) - 1] << '\n';
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