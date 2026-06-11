#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    
    const ll M = (1LL << N);
    vector<ll> A(M);
    for (ll i = 0; i < M; i++) {
        cin >> A[i];
    }

    //dp[i] := iの部分集合であるjについてA[j]が大きい順に上位二つを保持(A[j]ではなくjを保持)
    vector<pair<ll, ll>> dp(M, { 0, 0 });
    for (ll i = 1; i < M; i++) {
        vector<ll> candidate;

        //自分自身を含む
        candidate.push_back(i);

        //あとはiからビットを一つ降ろしたものについて調べれば十分
        for (ll j = 0; j < N; j++) {
            if (i & (1LL << j)) {
                candidate.push_back(dp[i ^ (1LL << j)].first);
                candidate.push_back(dp[i ^ (1LL << j)].second);
            }
        }

        //重複削除
        sort(candidate.begin(), candidate.end());
        candidate.erase(unique(candidate.begin(), candidate.end()), candidate.end());

        //A[k]の値でソート
        sort(candidate.begin(), candidate.end(), [&](ll lhs, ll rhs) {
            return A[lhs] > A[rhs];
        });

        //上位二つを保持
        dp[i].first = candidate[0];
        dp[i].second = candidate[1];
    }

    //各iについて上位二つとなるインデックスが確保されているのでA[index]の和を取れば良い
    ll ans = 0;
    for (ll i = 1; i < M; i++) {
        ans = max(ans, A[dp[i].first] + A[dp[i].second]);
        printf("%lld\n", ans);
    }
}