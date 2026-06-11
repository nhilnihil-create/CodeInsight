#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int main() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int g = gcd(n, m);
    for (int i = 0; i < g; i++) {
        if (s[n / g * i] != t[m / g * i]) return !(cout << -1 << endl);
    }
    cout << 1LL * n / g * m << endl;
    return 0;
}
