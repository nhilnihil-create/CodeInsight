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
ll n, m, k, ans, sum;
int a[N];
unordered_map<int, int> mp;

int main() {
    cin >> n >> m;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        int d = sum % m;
        if (mp.count(d)) {
            ans += mp[d];
        }
        ++mp[d];
    }
    cout << ans << endl;
    return 0;
}
