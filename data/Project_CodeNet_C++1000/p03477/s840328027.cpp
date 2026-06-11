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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a+b > c+d) cout << "Left" << endl;
    else if (a+b < c+d) cout << "Right" << endl;
    else cout << "Balanced" << endl;
    return 0;
}