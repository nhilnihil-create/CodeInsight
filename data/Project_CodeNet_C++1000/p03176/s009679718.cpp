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
const int maxn = 200005;
ll b[maxn];
int n;
void update(int x ,ll d) {
	while (x <= n) {
		b[x] = max(b[x], d);
		x += x & (-x);
	}
}
ll query(int x) {
	ll ret = 0;
	while (x) {
		ret = max(ret, b[x]);
		x -= x & (-x);
	}
	return ret;
}
void go() {
	cin >> n;
	int h[n + 5], w[n + 5];
	f(n) {
		cin >> h[i];
	}
	f(n) {
		cin >> w[i];
	}
	ll ans = 0;
	f(n) {
		ll v = query(h[i]) + w[i];
		ans = max(ans, v);
		update(h[i], v);
	}
	cout << ans << '\n';
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