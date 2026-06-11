#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> counts(100001,0);
    for (ll i=1; i<=100000; i++) {
        ll min = 100001;
        for (ll j=1; i-j>=0; j*=9) if (counts[i-j]<min) min = counts[i-j];
        for (ll j=1; i-j>=0; j*=6) if (counts[i-j]<min) min = counts[i-j];
        counts[i] = min+1;
    }
    cout << counts[n];
    return 0;
}