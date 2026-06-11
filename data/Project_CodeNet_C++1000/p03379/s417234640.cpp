#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<long long> X) {
    vector<pair<ll, ll>> indexvec;
    vector<pair<ll, ll>> ans;
    rep(i, N) { indexvec.push_back(pair<ll, ll>(X[i], i + 1)); }
    sort(indexvec.begin(), indexvec.end());
    ll m0 = indexvec[N / 2 - 1].first;
    ll m1 = indexvec[N / 2].first;
    rep(i, N) {
        if (i <= (N / 2 - 1)) {
            ans.push_back(pair<ll, ll>(indexvec[i].second, m1));
        } else if (i >= N / 2) {
            ans.push_back(pair<ll, ll>(indexvec[i].second, m0));
        }
    }
    sort(ans.begin(), ans.end());
    rep(i, N) { cout << ans[i].second << endl; }
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> X(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &X[i]);
    }
    solve(N, std::move(X));
    return 0;
}
