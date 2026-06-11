#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    int cnt = 0;
    int next = -1;
    rep(i, s.size()) {
        if (s[i] - '0' != 1) {
            next = s[i] - '0';
            break;
        } else
            cnt++;
    }
    if (k <= cnt)
        cout << 1 << endl;
    else
        cout << next << endl;
}