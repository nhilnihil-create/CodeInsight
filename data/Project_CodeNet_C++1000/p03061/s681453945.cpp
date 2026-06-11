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

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> gcdr(n);
    vector<int> gcdl(n);
    rep(i, n) {
        if (i == 0) gcdl[0] = a[i];
        else gcdl[i] = gcd(gcdl[i-1], a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) gcdr[n - 1] = a[i];
        else gcdr[i] = gcd(gcdr[i+1], a[i]);
    }
    int ans = 0;
    rep(i, n) {
        if (i == 0) {
            ans = max(ans, gcdr[i + 1]);
        }
        else if (i == n - 1) {
            ans = max(ans, gcdl[i - 1]);
        }
        else {
            ans = max(ans, gcd(gcdl[i-1], gcdr[i+1]));
        }
    }
    cout << ans << endl;
    return 0;
}
