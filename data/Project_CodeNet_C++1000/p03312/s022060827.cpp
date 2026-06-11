#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;

void update(ll& res, vector<pair<ll, ll>> candl, vector<pair<ll, ll>> candr) {
    for (auto pl : candl)for (auto pr : candr) {
        ll mn = min(min(pl.first, pl.second), min(pr.first, pr.second));
        ll mx = max(max(pl.first, pl.second), max(pr.first, pr.second));
        res = min(res, mx - mn);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)cin >> A[i];
    auto imos = A;
    imos.insert(imos.begin(), 0);
    rep(i, N)imos[i + 1] += imos[i];

    ll res = 1ll << 60;
    REP(mid, 2, N - 1) {
        vector<pair<ll, ll>> candl, candr;
        ll tgtl = imos[mid] / 2, tgtr = (imos.back() + imos[mid]) / 2;
        ll idxl = lower_bound(imos.begin(), imos.begin() + mid + 1, tgtl) - imos.begin() - 3;
        REP(l, idxl, idxl + 7) {
            if (0 < l && l < mid) {
                candl.push_back({ imos[mid] - imos[l], imos[l] });
            }
        }
        ll idxr = lower_bound(imos.begin() + mid + 1, imos.end(), tgtr) - imos.begin() - 3;
        REP(r, idxr, idxr + 7) {
            if (mid < r&&r < N) {
                candr.push_back({ imos.back() - imos[r],imos[r] - imos[mid] });
            }
        }
        update(res, candl, candr);
    }
    cout << res << endl;
    return 0;
}
