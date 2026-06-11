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

static inline bool check(char a) {
    return a == 'A' || a == 'C' || a == 'G' || a == 'T';
}
int main() {
    string s;
    cin >> s;
    int n=s.length();
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (check(s[i])) {
            ++cnt;
        } else {
            res = max(res, cnt);
            cnt = 0;
        }
    }
    res = max(res, cnt);
    cout << res << endl;
    return 0;
}
