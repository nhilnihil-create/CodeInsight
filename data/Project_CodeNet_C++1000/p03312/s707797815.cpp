#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
    lint N;
    cin >> N;

    vector<lint> A(N);
    for(auto& elem : A)  cin >> elem;

    vector<lint> sum(N+1, 0);
    for(int i=0; i<N; i++) sum[i+1] = sum[i] + A[i];

    lint ans = 1e18;
    for(lint j=0; j<=N; j++) {
        lint ok, ng;
        // ok: sum[0,i] <= sum[i,j]
        ok = 0;
        ng = j;
        while(ng - ok > 1) {
            lint mid = (ok+ng) / 2;
            (sum[mid]-sum[0] <= sum[j]-sum[mid] ? ok : ng) = mid;
        }
        lint i0 = ok, i1 = min(j,ok+1);

        // ok: sum[j,k] <= sum[k,N]
        ok = j;
        ng = N;
        while(ng - ok > 1) {
            lint mid = (ok+ng) / 2;
            (sum[mid]-sum[j] <= sum[N]-sum[mid] ? ok : ng) = mid;
        }
        lint k0 = ok, k1 = min(N,ok+1);

        lint res = 1e18;
        for(auto i : {i0, i1})
        for(auto k : {k0, k1}) {
            lint P = sum[i] - sum[0];
            lint Q = sum[j] - sum[i];
            lint R = sum[k] - sum[j];
            lint S = sum[N] - sum[k];
            lint mx = max({P,Q,R,S});
            lint mn = min({P,Q,R,S});
            res = min(res, mx-mn);
        }
        ans = min(res, ans);
    }

    cout << ans << endl;
}