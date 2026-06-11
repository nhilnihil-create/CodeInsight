#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll n;
    cin >> n;
    cout << 2*n/gcd(2, n) << endl;
    return 0;
}