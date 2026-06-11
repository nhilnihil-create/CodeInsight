#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll N;  cin >> N;
    cout << lcm(2, N) << endl;
}
