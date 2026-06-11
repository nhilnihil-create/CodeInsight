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
    lint n, m;
    cin >> n >> m;

    if (n >= 2 && m >= 2) cout << (n-2) * (m-2) << endl;
    else if (n >= 2) cout << n-2 << endl;
    else if (m >= 2) cout << m-2 << endl;
    else cout << 1 << endl;
    return 0;
}