#include <bits/stdc++.h>
using namespace std;

long long gcd(long long n, long long m) { return m ? gcd(m, n % m) : n; }

long long lcm(long long x, long long y) { return x * y / gcd(x, y); }

int main() {
    //
    long long n, m;
    string s, t;
    long long kekka;
    long long tmpN, tmpM;
    long long g;

    cin >> n >> m >> s >> t;

    kekka = lcm(n, m);
    g = gcd(n, m);

    tmpN = n / g;
    tmpM = m / g;

    for (long long i = 0; i < g; i++) {
        if (s.at(i * tmpN) != t.at(i * tmpM)) {
            cout << -1;
            return 0;
        }
    }

    cout << kekka;
    //
}