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

string s;
int ans;
int main() {
    cin >> s;
    int n = s.length();
    ans = n;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1])
            ans = min(ans, max(i, n - i));
    }
    cout << ans << endl;
    return 0;
}
