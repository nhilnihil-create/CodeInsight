#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

template <typename T> 
using V = vector<T>;

template <typename T>
using VV = vector<V<T>>;

struct Idx {
    ll i1, i2;
};

const ll S = (1ll << 18) + 10;
V<Idx> memo(S, Idx{0, 0});
V<ll> ans(S, 0);

int main() {
    ll N;
    cin >> N;
    V<ll> A(1ll << N);
    for (ll &a : A) cin >> a;
    memo[1] = (A[0] < A[1] ? Idx{1, 0} : Idx{0, 1});
    ans[1] = A[0] + A[1];
    for (ll i = 2; i < A.size(); i++) {
        ll idx1 = i, idx2 = 0;
        if (A[idx1] < A[idx2]) swap(idx1, idx2);
        bitset<60> bi(i);
        for (ll j = 0; j < 60; j++) {
            if (!bi.test(j)) continue;
            ll idx = (bi ^ bitset<60>(1ll << j)).to_ullong();
            V<ll> tmp = {idx1, idx2, memo[idx].i1, memo[idx].i2};
            sort(tmp.begin(), tmp.end(), [&](ll a, ll b){ return A[a] > A[b]; });
            auto ite = unique(tmp.begin(), tmp.end());
            tmp.erase(ite, tmp.end());
            idx1 = tmp[0];
            idx2 = tmp[1];
        }
        memo[i] = Idx{idx1, idx2};
        ans[i] = max(ans[i - 1], A[idx1] + A[idx2]);
    }
    for (ll i = 1; i < A.size(); i++) cout << ans[i] << '\n';
    return 0;
}
