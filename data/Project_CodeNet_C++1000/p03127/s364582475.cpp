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

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll gcd_num = 0;
    rep(i, n) cin >> a[i];
    rep(i, n-1) {
        if (i == 0) {
            gcd_num = gcd(a[i], a[i+1]);
        }
        else {
            gcd_num = gcd(gcd_num, a[i+1]);
        }
    }
    cout << gcd_num << endl;
    return 0;
}