#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> A(n);
    for (auto & a : A) cin >> a;

    ll res = 0;

    for (auto a : A) {
        while ((a % 2) == 0) {
            a /= 2;
            ++res;
        }
    }

    cout << res << endl;

}
