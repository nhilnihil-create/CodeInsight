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
ll pre[101][100001];
void go() {
	int n, k;
	cin >> n >> k;
	int x;
	cin >> x;
	f(x + 1) {
		pre[1][i] = i + 1;
	}
	fr(i,x+1,k+1) {
		pre[1][i] = x + 1;
	}
	for (int i = 2 ; i <= n ; i++) {
		int x;
		cin >> x;
		for (int j = 0 ; j <= k ; j++) {
			ll way;
			if (j <= x) {
				way = pre[i - 1][j];
			}
			else {
				way = (pre[i - 1][j] - pre[i - 1][j - x - 1] + mod) % mod;
			}
			if (j == 0) {
				pre[i][j] = way;
			}
			else {
				pre[i][j] = (pre[i][j - 1] + way) % mod;
			}
		}
	}
	if (!k) {
		cout << 1 << '\n';
	}
	else {
		cout << (pre[n][k] - pre[n][k - 1] + mod) % mod << '\n';
	}
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