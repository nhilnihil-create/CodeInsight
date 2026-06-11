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
    int r;
    cin >> r;
    if (r < 1200) cout << "ABC" << endl;
    else if (r < 2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
    return 0;
}