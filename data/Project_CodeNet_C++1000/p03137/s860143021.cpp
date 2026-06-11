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
    int n, m;
    cin >> n >> m;
    vector<ll> x(m);
    rep(i, m) cin >> x[i];
    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());
    vector<ll> dif(m-1);
    ll sum = 0;
    rep(i, m-1) {
        dif[i] = x[i+1] - x[i];
        sum += x[i+1] - x[i];
    }
    sort(dif.rbegin(), dif.rend());
    //cout << sum << endl;
    //for (auto d: dif) {
    //    cout << d << " ";
    //}
    //cout << endl;
    rep(i, n) {
        if (i == 0) continue;
        sum -= dif[i-1];
    }
    cout << sum << endl;
    return 0;
}
