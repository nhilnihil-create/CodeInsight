#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    string s;
    int k;
    cin >> s >> k;
    k--;
    int x = 0;
    rep(i, (int)s.size()) {
        if (s[i] != '1') {
            x = i;
            break;
        }
    }
    if (x <= k) cout << s[x] << endl;
    else cout << 1 << endl;
}