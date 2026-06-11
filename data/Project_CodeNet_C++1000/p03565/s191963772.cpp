//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define chmin(x,y) x = min(x, y)
#define chmax(x,y) x = max(x, y)
#define V vector
vector<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
vector<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

int main () {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    int st = -1;
    for (int i = 0; i + m - 1 < n; i++) {
        bool flag = true;
        rep(j, m) {
            if (!(s[i+j] == t[j] || s[i+j] == '?')) flag = false;
        }
        if (flag) chmax(st, i);
    }
    if (st == -1) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    rep(i, m) {
        s[st+i] = t[i];
    }
    rep(i, n) {
        if (s[i] == '?') cout << 'a';
        else cout << s[i];
    }
    cout << endl;
    return 0;
}