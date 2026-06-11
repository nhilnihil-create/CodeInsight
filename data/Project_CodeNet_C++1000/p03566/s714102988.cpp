#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double solve() {
    ll N;
    cin >> N;
    vector<ll> T(N), V(N);
    for ( int i = 0; i < N; i++ ) cin >> T[i];
    for ( int i = 0; i < N; i++ ) cin >> V[i];
    ll t_max = 0;
    for ( int i = 0; i < N; i++ ) {
        t_max += T[i];
    }
    vector<double> v(2*t_max+1, 1000);
    int ct = 0;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j <= 2*T[i]; j++ ) {
            v[ct] = min(v[ct], (double)V[i]);
            if ( j != 2*T[i] ) ct++;
        }
    }
    double cv = 0;
    for ( ll t = 0; t < 2*t_max; t++ ) {
        v[t] = cv;
        cv = min(cv+0.5, v[t+1]);
    }
    cv = 0;
    for ( ll t = 2*t_max; t > 0 ; t-- ) {
        v[t] = cv;
        cv = min(cv+0.5, v[t-1]);
    }
    double ans = 0;
    for ( ll t = 0; t < 2*t_max; t++ ) {
        ans += v[t] + v[t+1];
    }
    ans /= 4;
    return ans;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(16);
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}