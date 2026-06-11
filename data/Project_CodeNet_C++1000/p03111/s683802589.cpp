#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, A, B, C;
vector<ll> v;
ll ans = INF;

void dfs(int i, vector<ll> a) {
    if (i == N) {
        // A: 0 
        // B: 1
        // C: 2
        // 使わない: 3 
        map<ll, ll> mp;
        rep(k, a.size()) {
            if (a[k] == 3) continue;
            mp[a[k]]++;
        }
        if (mp.size() != 3) return;

        // 3種類ある
        ll x, y, z;
        x = y = z = 0;
        rep(k, a.size()) {
            if (a[k] == 0) {
                x += v[k];
            } else if (a[k] == 1) {
                y += v[k];
            } else if (a[k] == 2) {
                z += v[k];
            }
        }

        // cout << endl;
        // cout << endl;
        // rep(k, a.size()) {
        //     cout << a[k] << " ";
        // }
        ll connect_num = (mp[0] - 1) + (mp[1] - 1) + (mp[2] - 1);
        ll tmp = abs(A - x) + abs(B - y) + abs(C - z) + 10 * connect_num;
        // cout << tmp << endl;
        ans = min(ans, tmp);
        
        return;
    }

    map<ll, ll> mp;
    for (int j = 0; j < 4; j++) {
        a[i] = j;
        dfs(i + 1, a);
    }
}

int main() {
    cin >> N >> A >> B >> C;
    v.resize(N);
    rep(i, N) cin >> v[i];

    vector<ll> tmp(N, 0);
    dfs(0, tmp);

    cout << ans << endl;
}