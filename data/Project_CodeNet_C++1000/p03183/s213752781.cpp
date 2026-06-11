#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int N;
    cin >> N;
    vector<pair<pair<ll, ll>, ll>> box(N);
    for (int i = 0; i < N; i++) {
        ll w, s, v;
        cin >> w >> s >> v;
        box[i] = {{w, s}, v};
    }
    sort(box.begin(), box.end(), [](auto x, auto y){return x.first.first - y.first.second < y.first.first - x.first.second;});
    
    ll W = 10000;
    ll ans = 0;
    vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) dp[i+1][j] = dp[i][j];
        for (int j = 0; j <= box[i].first.second; j++) {
            ll cand = dp[i][j] + box[i].second;
            ans = max(ans, cand);
            ll nj = j+box[i].first.first;
            if (j+box[i].first.first <= W) dp[i+1][nj] = max(dp[i+1][nj], cand);
        }
    }
    cout << ans << endl;
    return 0;
}