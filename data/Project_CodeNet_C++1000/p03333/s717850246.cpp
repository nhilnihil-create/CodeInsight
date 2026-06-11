// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;

int L[MAXN], R[MAXN];

ll ans;

int n;

void solve() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &L[i], &R[i]);
	}

	++n;

	sort(L + 1, L + n + 1);
	reverse(L + 1, L + n + 1);
	sort(R + 1, R + n + 1);

	for (int i = 1; i <= n; ++i) {
		if (L[i] > R[i]) {
			ans += (L[i] - R[i]);
		}
	}

	printf("%lld\n", ans * 2);	
}

int main() {
	int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}