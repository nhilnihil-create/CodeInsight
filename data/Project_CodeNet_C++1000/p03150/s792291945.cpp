#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    bool res = false;

    for (int i = 0; i <= 7; i++) {
        int j = 7 - i;
        string pre = s.substr(0, i);
        string suf = s.substr(n-j, j);
        string cp = pre + suf;
        if (cp == "keyence") res = true;
    }

    if (res) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}