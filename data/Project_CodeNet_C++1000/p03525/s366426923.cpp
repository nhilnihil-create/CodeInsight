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

    if(24 <= n) {
        cout << 0 << endl;
        return 0;
    }

    if(n == 23) {

        sort(d.begin(), d.end());

        int flag = 0;
        for(int i = 0; i <= 20; i += 2) {
            int k = i/2 + 1;
            if(d[i] != k || d[i+1] != k) {
                flag = 1;
            }
        }
        if(d[22] != 12) {
            flag = 1;
        }

        if(flag) {
            cout << 0;
        }
        else {
            cout << 1;
        }

        cout << endl;
        return 0;
    }

    int ans = 0;
    for(int b = 0; b < (1<<n); b++) {

        vector<int> t(n+1);
        rep(i, n) {
            if(b & 1<<i) {
                t[i] = 24-d[i];
            }
            else {
                t[i] = d[i];
            }
        }

        int u = 30;
        rep(i, n) {
            for(int j = i+1; j <= n; j++) {
                int x = abs(t[i] - t[j]);
                int y = min(x, 24-x);
                u = min(u, y);
            }
        }

        ans = max(ans, u);
    }

    cout << ans << endl;
    return 0;
}