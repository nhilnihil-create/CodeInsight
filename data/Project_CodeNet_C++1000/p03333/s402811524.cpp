#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

ll solve() {
    ll N, l, r;
    cin >> N;
    vector<ll> L(N), R(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> L[i] >> R[i];
    }
    vector<int> il(N), ir(N);
    for ( int i = 0; i < N; i++ ) {
        il[i] = i;
        ir[i] = i;
    }
    sort(il.begin(), il.end(), [&](int i1, int i2) { return L[i1] > L[i2];});   //desc
    sort(ir.begin(), ir.end(), [&](int i1, int i2) { return R[i1] < R[i2];});   //asc

    auto calc = [&](int f) {
        ll d = 0;
        vector<bool> used(N);
        int jl = 0, jr = 0;
        ll c = 0;
        for( int cnt = 0; cnt < N; cnt++ ) {
            int i;
            if ( f == 0 ) {
                while ( used[il[jl]] ) jl++;
                i = il[jl];
            } else {
                while ( used[ir[jr]] ) jr++;
                i = ir[jr];
            }
            if ( c < L[i] ) {
                d += L[i] - c;
                c = L[i];
            } else if ( R[i] < c ) {
                d += c - R[i];
                c = R[i];
            }
            f = 1 - f;
            used[i] = true;
        }
        d += abs(c);
        return d;
    };

    ll ans = max(calc(0), calc(1));
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}