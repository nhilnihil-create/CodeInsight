// Why am I so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

map<string, int> S[20];

int pw[20];

char s[45];

ll ans;

int n;

void pre() {
    pw[0] = 1;

    for (int i = 1; i < 20; ++i) {
        pw[i] = (pw[i - 1] << 1);
    }
}

bool bit(int m, int p) {
    return m & pw[p];
}

void solve() {
    scanf("%d %s", &n, s);
    string a, b;

    for (int m = 0; m < pw[n]; ++m) {
        a.clear();
        b.clear();

        for (int i = 0; i < n; ++i) {
            if (bit(m, i)) {
                a += s[n + i];
            }
            else {
                b += s[n + i];
            }
        }

        reverse(all(b));
        ++S[b.size()][b + a];
    }

    for (int m = 0; m < pw[n]; ++m) {
        a.clear();
        b.clear();

        for (int i = 0; i < n; ++i) {
            if (bit(m, i)) {
                a += s[i];
            }
            else {
                b += s[i];
            }
        }

        reverse(all(b));

        auto it = S[n - b.size()].find(a + b);

        if (it != S[n - b.size()].end()) {
            ans += (it -> se);
        }
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