#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n);
    for (auto & a : A) cin >> a;
    copy(A.begin(), A.end(), B.begin());

    sort(B.begin(), B.end());
    ll m1 = B[n/2-1];
    ll m2 = B[n/2];

    for (auto a : A) {
        if (a <= m1) {
            cout << m2 << endl;
        } else {
            cout << m1 << endl;
        }
    }

    
}
