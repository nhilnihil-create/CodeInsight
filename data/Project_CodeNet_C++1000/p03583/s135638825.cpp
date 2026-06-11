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
    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; ++h) {
        for (ll n = 1; n <= 3500; ++n) {
            ll a = 4 * h * n;
            ll b = N * n;
            ll c = N * h;
            ll d = N * h * n;
            if (a - b - c >= 1 && d % (a - b - c) == 0) {
                cout << h << " " << n << " " << d / (a - b - c) << endl;
                return 0;
            }
        }
    }
    return 0;
}
