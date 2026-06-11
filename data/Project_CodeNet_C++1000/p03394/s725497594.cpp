#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    if ( N == 3 ) {
        cout << "2 5 63" << "\n";
        return 0;
    }
    ll n = 2, c = 0, s = 0;
    vector<ll> v;
    ll ng = -1;
    while ( c < N ) {
        if ( n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
            v.push_back(n);
            s += n;
            c++;
        }
        n++;
    }
    while ( s % 30 != 0 ) {
        for(;;) {
            if ( n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
                ll ss = s + n;
                for ( int i = 0; i < v.size(); i++ ) {
                    if ( (ss - v[i]) % 30 == 0 ) {
                        v.push_back(n);
                        ng = v[i];
                        s += n;
                        s -= v[i];
                        break;
                    }
                }
            }
            if ( ng > 0 ) break;
            n++;
        }
    }
    vector<ll> ans;
    for ( int i = 0; i < v.size(); i++ ) {
        if ( v[i] != ng ) {
            ans.push_back(v[i]);
        }
    }
    for ( int i = 0; i < ans.size(); i++ ) {
        cout << (i != 0 ? " " : "") << ans[i];
    }
    cout << "\n";

    return 0;
}

int main() {
    solve();
    return 0;
}