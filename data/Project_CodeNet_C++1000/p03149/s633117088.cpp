//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using llint = long long;
using vint = vector<int>;
using vvint = vector<vector <int>>;
const int INF = 1e9;
const llint llINF = 1e18;

int main () {
    vint n(4);
    rep(i, 4) cin >> n[i];
    sort(all(n));
    if (n[0] == 1 &&n[1] == 4 &&n[2] == 7 &&n[3] == 9){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}