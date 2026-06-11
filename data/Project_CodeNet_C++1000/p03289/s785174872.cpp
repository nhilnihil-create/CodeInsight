#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string s;
    cin >> s;
    bool ans = true;

    if (s[0] != 'A')ans = false;
    string s_ = s.substr(2, s.size() - 3);
    int cnt = 0;
    for (auto sr : s_)if (sr == 'C')cnt++;
    if (cnt != 1)ans = false;
    cnt = 0;
    for (auto sr : s)if (sr >= 'a')cnt++;
    if (cnt != s.size() - 2)ans = false;
    if (ans) {
        cout << "AC" << endl;
    }
    else {
        cout << "WA" << endl;
    }
    return 0;
}