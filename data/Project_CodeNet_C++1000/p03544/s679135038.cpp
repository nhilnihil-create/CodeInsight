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
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> num;
    num.push_back(2);
    num.push_back(1);
    ll ans = 3;
    for (int i = 2; i <= n; ++i) {
        ans = num[i-1] + num[i-2];
        num.push_back(ans);
        //cout << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
