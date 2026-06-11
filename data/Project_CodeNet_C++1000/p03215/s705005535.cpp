#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n); vector<vector<ll>> b(n, vector<ll>(n, 0));
    queue<pair<int, int>> cur, nxt;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int l = 0; l < n; l++) for (int r = l; r < n; r++){
        b[l][r] = b[l][max(0, r - 1)] + a[r];
        cur.push({l, r});
    }

    auto count = [&](ll bit, bool update) -> ll{
        ll cnt = 0, l, r, ok;
        while (!cur.empty()){
            tie(l, r) = cur.front(); cur.pop();
            ok = (bit & b[l][r]);
            if (ok) cnt++;
            if (!update || ok) nxt.push({l, r});
        }
        swap(cur, nxt);
        return cnt;
    };

    for (int nd = 40; nd >= 0; nd--){
        ll bit = 1LL << nd;
        if (count(bit, false) >= k) {
            count(bit, true);
            ans += bit;
        }
    }

    cout << ans << endl;
    return 0;
}
