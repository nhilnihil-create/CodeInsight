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

struct S {
    ll x, y, z;
};

const int N = 1005;
int n, m;
ll ans;
S a[N];
ll cont[N];

void solve(int t1, int t2, int t3) {
    for (int i = 0; i < n; ++i) {
        ll c = 0;
        c += t1 ? -a[i].x : a[i].x;
        c += t2 ? -a[i].y : a[i].y;
        c += t3 ? -a[i].z : a[i].z;
        cont[i] = c;
    }
    sort(cont, cont + n, greater<ll>());
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += cont[i];
    }
    ans = max(ans, sum);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                solve(i, j, k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
