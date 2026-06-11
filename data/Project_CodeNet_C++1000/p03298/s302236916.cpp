// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int mod = (int)1e9 + 7;
const int mod2 = (int)1e9 + 9;
const int P = (int)31;
const int P2 = (int)37;

vector<pair<int, int>> cnt[20];

char s[40];

int pw[20];

ll ans;

int n;

void pre() {
	pw[0] = 1;

	for (int i = 1; i < 20; ++i) {
		pw[i] = (pw[i - 1] << 1);
	}
}

pair<int, int> h(string s) {
	pair<int, int> ret;

	int curP = 1, curP2 = 1;

	for (int i = 0; i < s.size(); ++i) {
		ret.fi = (ret.fi + curP * 1ll * (s[i] - 'a' + 1)) % mod;
		ret.se = (ret.se + curP2 * 1ll * (s[i] - 'a' + 1)) % mod2;
		curP = (curP * 1ll * P) % mod; 
		curP2 = (curP2 * 1ll * P2) % mod2;
	}

	return ret;
}

void solve() {
	scanf("%d %s", &n, s);

	for (int m = 0; m < pw[n]; ++m) {
		string a, b;

		for (int i = 0; i < n; ++i) {
			if (m & pw[i]) {
				a += s[n + i];
			}
			else {
				b += s[n + i];
			}
		}

		reverse(all(b));
		cnt[b.size()].pb(h(b + a));
	}

	for (int i = 0; i <= n; ++i) {
		sort(all(cnt[i]));
	}

	for (int m = 0; m < pw[n]; ++m) {
		string a, b;

		for (int i = 0; i < n; ++i) {
			if (m & pw[i]) {
				a += s[i];
			}
			else {
				b += s[i];
			}
		}

        reverse(all(b));                                    
		auto it = equal_range(all(cnt[n - b.size()]), h(a + b));
		ans += (it.se - it.fi);
	}

	printf("%lld\n", ans);
}

int main() {
    int tt = 1;

    pre();

    while (tt--) {
        solve();
    }

    return 0;
}