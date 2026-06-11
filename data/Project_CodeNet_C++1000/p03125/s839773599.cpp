#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using llint = long long;
using vint = vector<int>;
using vvint = vector<vector <int>>;
const llint INF = 1e9;
const llint llINF = 1e18;

int main () {
    int a, b; cin >> a >> b;
    if (b % a == 0) cout << a + b << endl;
    else cout << b - a << endl;
    return 0;
}