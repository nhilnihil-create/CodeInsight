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
    int k;
    cin >> k;
    int n = s.size();

    set<string> st;

    rep(i, n) {
        string t = "";
        for (int j = i; j < n; j++) {
            if (t.size() > k) break;
            t += s[j];
            st.insert(t);
        }
    }

    int c = 0;
    for (auto&& e : st) {
        c++;
        if (c == k) cout << e << endl;
    }
    return 0;
}