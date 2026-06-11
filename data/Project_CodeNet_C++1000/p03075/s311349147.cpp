#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    vector<ll> A(5);
    for ( int i = 0; i < 5; i++ ) cin >> A[i];
    ll K;
    cin >> K;
    return (A[4]-A[0]) > K;
}

int main() {
    string ans = solve() ? ":(" : "Yay!";
    cout << ans << "\n";
    return 0;
}