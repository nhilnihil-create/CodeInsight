#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using Grid = vector<vector<int>>;
using vi = vector<int>;

int main() {
    int N, K;
    cin >> N >> K;
    vi v(N);
    rep(i, N) cin >> v[i];
    ll ans = 0;

    rep(l, min(N, K)+1) {
        rep(r, min(N - l, K - l)+1) {
            if (l + r == 0)
                continue;
            vi a;
            a.reserve(l + r);
            rep(i, l) a.push_back(v[i]);
            rep(i, r) a.push_back(v[N - 1 - i]);
            sort(rall(a));
            int back = min(K - l - r, l + r);
            while (back > 0 && (*a.rbegin()) < 0)
                a.pop_back(), back--;
            ans = max(ans, accumulate(all(a), 0ll));
        }
    }
    cout << ans << endl;
}