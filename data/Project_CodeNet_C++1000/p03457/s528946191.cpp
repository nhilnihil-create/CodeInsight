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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    bool flg = true;
    vector<int> t(n+1, 0);
    vector<int> x(n+1, 0);
    vector<int> y(n+1, 0);
    rep(i, n) cin >> t[i+1] >> x[i+1] >> y[i+1];
    rep(i, n) {
        if (abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]) > t[i+1] - t[i]) {
            flg = false;
        }
        else if ((abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]) - (t[i+1]-t[i]))%2 != 0) {
            flg = false;
        } 
    }
    cout << ((flg) ? "Yes" : "No") << endl;
    return 0;
}
