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

int n, ans, cnt;
string s;
int x[26], y[26];
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        ++y[s[i] - 'a'];
    }

    for (int i = 0; i < n - 1; ++i) {
        int d = s[i] - 'a';
        if (x[d] == 0 && y[d] > 1) {
            ++cnt;
        }
        if (x[d] > 0 && y[d] == 1) {
            --cnt;
        }
        ++x[d];
        --y[d];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
