#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
ll c;
ll x[maxn];
ll v[maxn];

ll a[maxn], b[maxn];
ll suffix_b[maxn];
ll prefix_a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>c;
    for (int i=1; i<=n; i++) {
	cin>>x[i]>>v[i];
    }

    x[n+1]=c;

    for (int i=n; i>=1; i--) {
	b[i]=b[i+1] + (v[i] - (x[i+1]-x[i]));
    }
    for (int i=n; i>=1; i--) {
	suffix_b[i] = max(b[i], suffix_b[i+1]);
    }
    

    for (int i=1; i<=n; i++) {
	a[i] = a[i-1] + (v[i] - (x[i]-x[i-1]));
    }
    for (int i=1; i<=n; i++) {
	prefix_a[i] = max(prefix_a[i-1], a[i]);
    }



    ll ans = 0;
    for (int i=0; i<=n; i++) {
	ll cur = a[i];
	ans = max(ans, cur);
	cur -= x[i];
	cur += suffix_b[i+1];
	ans = max(ans, cur);
    }

    for (int i=n; i>0; i--) {
	ll cur = b[i];
	ans = max(cur, ans);
	cur -= (c-x[i]);
	cur += prefix_a[i-1];
	ans = max(ans, cur);
    }

    out(ans);
    return 0;
}
