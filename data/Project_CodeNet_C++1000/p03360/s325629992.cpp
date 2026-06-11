#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    vector<ll> A(3);

    for (auto & a : A) cin >> a;
    ll n;
    cin >> n;

    ll ma = max(A[0], max(A[1], A[2]));
    ll res = A[0] + A[1] + A[2] - ma;
    res += ma << n;
    cout << res << endl;
}
