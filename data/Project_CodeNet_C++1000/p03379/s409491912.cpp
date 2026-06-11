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
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    vector<ll> tmp = x;
    sort(tmp.begin(), tmp.end());
    ll med_l = tmp[n/2-1];
    ll med_h = tmp[n/2];
    rep(i, n) {
        if (x[i] <= med_l) {
            cout << med_h << endl;
        }
        else {
            cout << med_l << endl;
        }
    }
    return 0;
}
