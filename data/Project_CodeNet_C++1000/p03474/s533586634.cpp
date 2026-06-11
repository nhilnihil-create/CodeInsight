#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

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
string s;

int main() {
    cin >> n >> m >> s;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (!isdigit(s[i]))
            ok = false;
    }
    if (s[n] != '-')
        ok = false;
    for (int i = 0; i < m; ++i) {
        if (!isdigit(s[n + 1 + i]))
            ok = false;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
