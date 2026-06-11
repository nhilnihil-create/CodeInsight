#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int a, b;
    cin >> a >> b;
    if (b % a == 0) cout << a+b << endl;
    else cout << b-a << endl;
    return 0;
}