#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> sushi(N);
    REP(i, N) {
        int t, d;
        cin >> t >> d;
        sushi[i] = {d, t - 1};
    }
    sort(ALL(sushi));
    reverse(ALL(sushi));
    ll s = 0;
    ll x = 0;
    vector<bool> used(N);
    vector<int> discard;
    REP(i, K) {
        int d = sushi[i].first, t = sushi[i].second;
        s += d;
        if (!used[t]) {
            x++;
            used[t] = true;
        } else {
            discard.push_back(d);
        }
    }
    ll ans = s + x * x;
    sort(ALL(discard));
    reverse(ALL(discard));
    for (int i = K; i < N && !discard.empty(); i++) {
        int d = sushi[i].first, t = sushi[i].second;
        if (used[t]) continue;
        used[t] = true;
        s -= discard.back();
        discard.pop_back();
        s += d;
        x++;
        ans = max(ans, s + x * x);
    }
    cout << ans << endl;
}