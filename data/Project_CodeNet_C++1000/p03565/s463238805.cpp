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

string is_match(string& s, string& t) {
    int n = s.size();
    int m = t.size();

    rep(i, n-m+1) {
        string u = s.substr(n-m-i, m);

        bool f = true;

        rep(j, m) {
            if (u[j] != t[j] && u[j] != '?') f = false;
        }

        if (f) {
            string res = s;
            rep(j, m) {
                res[n-m-i+j] = t[j];
            }
            return res;
        }
    }

    return "@";
}

int main() {
    string s, t;
    cin >> s >> t;

    string rest = is_match(s, t);
    if (rest == "@") {
        cout << "UNRESTORABLE" << endl;
    }
    else {
        rep(i, rest.size()) {
            cout << (rest[i] == '?' ? 'a' : rest[i]);
        }
        cout << endl;
    }

    return 0;
}