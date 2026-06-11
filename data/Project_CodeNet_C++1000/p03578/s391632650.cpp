#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    ll N, M, d, t;
    cin >> N;
    map<ll, ll> D, T;
    for ( int i = 0; i < N; i++ ) {
        cin >> d;
        D[d]++;
    }
    cin >> M;
    for ( int i = 0; i < M; i++ ) {
        cin >> t;
        T[t]++;
    }
    for ( auto p : T ) {
        if ( D[p.first] < p.second ) return false;
    }
    return true;
}

int main() {
    string ans = solve() ? "YES" : "NO";
    cout << ans << "\n";
    return 0;
}