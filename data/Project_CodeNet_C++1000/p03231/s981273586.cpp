#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    long long g = __gcd(n, m), l = n * m / g;
    for (int i = 0; i < g; i++) {
        if (s[i * n / g] != t[i * m / g]) {
            l = -1;
            break;
        } 
    }
    cout << l << endl;
}