#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1e5 + 5, INF = 1e9 + 5, M = N + N;
int a[N], pref[N], t[M];
int n;

int que(int x) {
	x += N;
	int s = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		s += t[x];
	return s;
}

void upd(int x, int y) {
	x += N;
	for (; x < M; x |= x + 1) {
		t[x] += y;
	}
}

ll get_ct_at_least_p(ll p) {
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + (a[i] < p);
	} 

	fill(t, t + M, 0);

	for (int i = 0; i <= n; i++) {
		int x = i - 2 * pref[i];
		ans += que(x);
		upd(x, 1);
	}

	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    ll all_pairs_ct = n * (ll)(n + 1) / 2;

    ll l = 0, r = INF;
    while (r - l > 1) {
    	ll p = (l + r) >> 1;

    	if ((all_pairs_ct - get_ct_at_least_p(p)) * 2 <= all_pairs_ct) {
    		l = p;
    	}
    	else {
    		r = p;
    	}
    }

    cout << l;

    return 0;   
}