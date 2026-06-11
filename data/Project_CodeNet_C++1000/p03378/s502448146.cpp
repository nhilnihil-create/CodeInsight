#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> A(m);
    for (auto & a : A) {
        cin >> a;
    }
    ll left = 0, right = 0;
    for (auto a : A) {
        if (a < x) ++left;
        else ++right;

    }

    cout << min(left, right) << endl;

}
