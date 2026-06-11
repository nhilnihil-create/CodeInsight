#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> X(N);
    rep(i, N) {
        ll tmp;
        cin >> tmp;
        X[i] = make_pair(tmp, i);
    }

    sort(X.begin(), X.end());
    // rep(i, N) { cout << X[i].first << "," << X[i].second << endl; }

    vector<ll> ans(N);
    rep(i, N) {
        if (i < N / 2)
            ans[X[i].second] = X[N / 2].first;
        else
            ans[X[i].second] = X[N / 2 - 1].first;
    }

    repv(ans) { cout << *it << endl; }
    return 0;
}