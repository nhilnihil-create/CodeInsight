#include <bits/stdc++.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long int;
using namespace std;

int main() {
    fastio;
    string s;
    cin >> s;
    cout << 700 + (int)count(s.begin(), s.end(), 'o') * 100;
}