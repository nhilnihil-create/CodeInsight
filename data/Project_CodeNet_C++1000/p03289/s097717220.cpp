#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    bool a = 0, b = 0, c = 0;
    if (s[0] == 'A')
        a = 1;
    int cnt = 0;
    for (int i = 2; i <= s.size() - 2; i++) {
        if (s[i] == 'C')
            cnt++;
    }
    if (cnt == 1)
        b = 1;
    cnt = 0;
    rep(i, s.size()) {
        if (islower(s[i]))
            cnt++;
    }
    if (cnt == s.size() - 2)
        c = 1;

    if (a && b && c) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }

    return 0;
}