#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int a[n+2] = {};  // a[0] = a[n+1] = 0 
    rep(i,n) cin >> a[i+1];
    int cost_change[n+1];
    for (int i = 1; i < n+1; i++) {
        int pre = abs(a[i] - a[i-1]) + abs(a[i+1] - a[i]);
        int post = abs(a[i+1] - a[i-1]);
        cost_change[i] = post - pre;
    }
    int64_t standard_cost = 0;
    rep(i,n+1) {
        standard_cost += abs(a[i+1] - a[i]);
    }
    for (int i = 1; i < n+1; i++) {
        int64_t cost = standard_cost + cost_change[i];
        cout << cost << endl;
    }
}