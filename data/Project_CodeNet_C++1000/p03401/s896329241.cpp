#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int n; cin >> n;
    vector<int> a(n+2);
    rep(i, n) cin >> a[i+1];
    a[0] = a[n+1] = 0;
    int total = 0;
    rep(i, n+1) {
        total += abs(a[i]-a[i+1]);
    }
    //cout << total;
    for (int i=1; i<=n; i++) {
        int x = total
              -(abs(a[i-1]-a[i])+abs(a[i]-a[i+1]))
              +(abs(a[i-1]-a[i+1]));
        cout << x << endl;
    }
}
