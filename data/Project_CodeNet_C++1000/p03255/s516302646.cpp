#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<ll, ll>;
using namespace std;

template<class t> void vin(vector<t>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

ll sum[303030];

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N);

    if (N == 1) {
        cout << 2*X + x[0]*5 << endl;
        return 0;
    }

    rep(i, N) cin >> x[i];
    rep(i, N) {
        sum[i+1] = x[i] + sum[i];
    }
    ll ans = 1LL<<62;
    for (int k=1; k<=N; ++k) {
        ll result = k*X;
        ll n = N, b = 5;
        while (n > 0) {
            bool ok = false;
            if (b == 5) {
                if (n-k*2 < 0) break;
                result += b * (sum[n] - sum[n-k*2]);
                n -= k*2;
                ok = true;
            }
            else {
                if (n-k < 0) break;
                result += b * (sum[n] - sum[n-k]);
                n -= k;
                ok = true;
            }
            if (!ok) break;
            b += 2;
            if (result < 0) break;
        }
        if (n >= 0) {
            result += b * sum[n];
            if (result > 0LL) ans = min(ans, result);
        }
    }
    cout << ans+N*X << endl;
    return 0;
}
