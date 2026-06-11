// NOT MY CODE
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define ALL(x) begin(x), end(x)
using ll = long long;
using namespace std;

void split(int n, string const & t, unordered_map<string, int> & f) {
    REP (x, 1 << n) {
        string a, b;
        REP (i, n) {
            (x & (1 << i) ? a : b) += t[i];
        }
        f[a + "/" + b] += 1;
    }
}

int main() {
    // input
    int n; cin >> n;
    string s; cin >> s;

    // solve
    string t1 = s.substr(0, n);
    string t2 = s.substr(n);
    reverse(ALL(t2));
    unordered_map<string, int> f, g;
    split(n, t1, f);
    split(n, t2, g);
    ll cnt = 0;
    for (auto const & it : f) {
        if (g.count(it.first)) {
            cnt += (ll)it.second * g[it.first];
        }
    }

    // output
    cout << cnt << endl;
    return 0;
}