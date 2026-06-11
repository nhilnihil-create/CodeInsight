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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    auto b = a;
    sort(a.begin(), a.end());
    int mid = n / 2;
    int minv = a[mid-1];
    int maxv = a[mid];
    rep(i, n) {
        if (maxv > b[i]) {
            cout << maxv << endl;
        }
        else {
            cout << minv << endl;
        }
    }
    return 0;
}