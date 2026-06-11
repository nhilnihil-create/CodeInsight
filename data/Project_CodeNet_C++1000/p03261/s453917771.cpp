#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n, m, k, ans;
unordered_set<string> seen;
string s, p;

int main() {
    bool ok = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (seen.count(s)) {
            ok = false;
        }
        seen.insert(s);
        if (i > 0) {
            if (s[0] != p.back()) {
                ok = false;
            }
        }
        p = s;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
