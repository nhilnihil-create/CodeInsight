#include <iostream>
#include <string>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) { return (!b) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int g = gcd(n, m);
    for (int i = 0; i < g; ++i) {
        if (s[i * (n / g)] != t[i * (m / g)]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << lcm(n, m) << '\n';
}