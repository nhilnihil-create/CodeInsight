#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    rep(i, n) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());

    vector<int> t(n+1);
    rep(i, n) {
        if(i%2 == 0) {
            t[i] = d[i];
        }
        else {
            t[i] = 24 - d[i];
        }
    }

    int ans = 30;
    rep(i, n) {
        for(int j = i+1; j <= n; j++) {
            int x = abs(t[i] - t[j]);
            int y = min(x, 24-x);
            ans = min(ans, y);
        }
    }

    cout << ans << endl;
    return 0;
}