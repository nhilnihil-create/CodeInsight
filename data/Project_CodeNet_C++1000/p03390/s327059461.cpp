#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll solve(ll a, ll b) {
    if (a == b) return (a - 1) * 2;
    ll limit = a * b - 1;
    ll low = 1, high = 1LL << 31;
    ll rv;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll x = (mid + 1) / 2;
        if(x * (mid + 1 - x) <= limit) {
            rv = mid;
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    return rv - 1;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        long long a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}