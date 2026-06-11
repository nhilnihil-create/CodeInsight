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

const int N = 3e5 + 5;
int n, ans;
string s;
int l[N], r[N];
int main() {
    cin >> n >> s;
    ans = n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        l[i] = sum;
        if (s[i] == 'W')
            ++sum;
    }
    sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        r[i] = sum;
        if (s[i] == 'E')
            ++sum;
    }
    for (int i = 0; i < n; ++i) {
        ans = min(ans, l[i] + r[i]);
    }
    cout << ans << endl;
    return 0;
}
