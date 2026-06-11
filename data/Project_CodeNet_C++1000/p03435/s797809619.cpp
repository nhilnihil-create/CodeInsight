#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    int c1 = min({c[0][0], c[0][1], c[0][2]});
    vector<int> l(3);
    l[0] = c[0][0] - c1;
    l[1] = c[0][1] - c1;
    l[2] = c[0][2] - c1;
    int c2 = min({c[1][0], c[1][1], c[1][2]});
    bool ok = true;
    rep(i, 3) {
        if (c[1][i] - c2 != l[i]) {
            ok = false;
            break;
        } 
    }
    int c3 = min({c[2][0], c[2][1], c[2][2]});
    rep(i, 3) {
        if (c[2][i] - c3 != l[i]) {
            ok = false;
            break;
        }
    } 
    if (ok) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
