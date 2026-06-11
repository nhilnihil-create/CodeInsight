#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, x;
vector<ll> a;
int main() {
    cin >> N >> x;
    a.resize(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    rep(i, N) {
        if (i == N - 1) {
            if (a[i] == x) ans++;
            x -= a[i];
            continue;
        } 

        if (x >= a[i]) {
            x -= a[i];
            ans++;
        }
    }
    cout << ans << endl;
}