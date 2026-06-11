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
    string s, t;
    cin >> s >> t;

    sort(all(s));
    sort(all(t));
    reverse(all(t));

    if (s < t) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}