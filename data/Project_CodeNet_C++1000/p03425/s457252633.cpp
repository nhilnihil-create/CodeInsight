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

char table[] = {'M', 'A', 'R', 'C', 'H'};

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    map<char, int> mp;

    rep(i, n) {
        char c = s[i][0];
        mp[c]++;
    }

    lint res = 0;

    rep(i, 5) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                lint t = 1;
                t *= mp[table[i]];
                t *= mp[table[j]];
                t *= mp[table[k]];
                res += t;
            }
        }
    }

    cout << res << endl;
    return 0;
}