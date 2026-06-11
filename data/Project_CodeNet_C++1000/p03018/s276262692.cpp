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

    lint res = 0;
    lint c = 0;

    rep(i, n) {
        char ch = s[i];

        if (ch == 'A') {
            c++;
        }
        else if (ch == 'B') {
            if (i+1 < n && s[i+1] == 'C') {
                res += c;
                i++;
            }
            else {
                c = 0;
            }
        }
        else {
            c = 0;
        }
    }

    cout << res << endl;
    return 0;
}