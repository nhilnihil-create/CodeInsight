#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, M;
vector<ll> A;
vector<ll> sum;

int main() {
    cin >> N >> M;
    A.resize(N);
    rep(i, N) cin >> A[i];
    sum.resize(N + 1);
    sum[0] = 0;

    rep(i, N) {
        sum[i + 1] = (sum[i] + A[i]) % M;
    }

    // rep(i, N + 1) {
    //     cout << sum[i] << endl;
    // }
    map<ll, ll> mp;

    rep(i, N + 1) {
        mp[sum[i]]++;
    }

    ll ans = 0;
    for (auto m : mp) {
        // cout << m.first << " " << m.second << endl;
        ll tmp = m.second * (m.second - 1) / 2;
        ans += tmp;
    }

    cout << ans << endl;
}