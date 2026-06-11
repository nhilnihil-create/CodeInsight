#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<ll> s(N + 1, 0);
    rep(i, N) {
        cin >> A[i];
        s[i + 1] = s[i] + A[i];
    }
    ll ans = 1e18;
    for (int i = 2; i < N - 1; i++) {
        int p = distance(s.begin(), upper_bound(s.begin(), s.begin() + i, s[i] / 2));
        int q = distance(s.begin(), upper_bound(s.begin() + i, s.end(), (s[i] + s[N]) / 2));
        //cout << i << " " << p << " " << q << endl;
        for (int j = p - 1; j < p + 2; j++) {
            if (j < 1 || j >= i) continue;
            for (int k = q - 1; k < q + 2; k++) {
                if (k <= i || k > N - 1) continue;
                ll smin = 1e18, smax = -1;
                smin = min(smin, s[j]);
                smax = max(smax, s[j]);
                smin = min(smin, s[i] - s[j]);
                smax = max(smax, s[i] - s[j]);
                smin = min(smin, s[k] - s[i]);
                smax = max(smax, s[k] - s[i]);
                smin = min(smin, s[N] - s[k]);
                smax = max(smax, s[N] - s[k]);
                //cout << "i=" << i << " j=" << j << " k=" << k << " smin=" << smin << " smax=" << smax << endl;
                ans = min(ans, smax - smin);
            }
        }
    }
    cout << ans << endl;
}