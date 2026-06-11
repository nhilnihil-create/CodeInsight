#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n, x;
    cin >> n;
    cin >> x;
    vector<ll> M(n);
    ll cheap = 1e9;
    ll sum = 0;
    for (auto & m : M ) {
        cin >> m;
        cheap = min(cheap, m);
        sum += m;
    }

    cout << (n + (x - sum)/cheap) << endl;
}
