#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

bool check(ll x, ll a, ll b) {
    ll p = a*b;
    ll m = x/2;
    for (ll i = max(1LL, m-10); i<=min(x, m+10); ++i) {
        ll aa = i, bb = x - i + 1;
        if (aa >= a) aa++;
        if (bb >= b) bb++;
        if (aa*bb >= p) return false;
    }
    return true;
}

int main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        ll a, b;
        cin >> a >> b;
        ll ok = 0, ng = 1e10;
        while (ng-ok>1) {
            ll m = (ok + ng) / 2;
            if (check(m, a, b)) ok = m;
            else ng = m;
        }
        cout << ok << endl;
    }
    return 0;
}
