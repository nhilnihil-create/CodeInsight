#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// r -> l or l -> r
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = 1e9;
    rep(i,n) {
        int l = i;
        int r = i+k-1;
        if(r >= n) break;
        int a = abs(x[l]) + abs(x[l]-x[r]);
        int b = abs(x[r]) + abs(x[r]-x[l]);
        int res = min(a, b);
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}