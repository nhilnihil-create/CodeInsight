#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans = 1e9;
    sort(all(h));
    for(int i = 0; (i+k-1)<n; ++i) {
        int temp = abs(h[i+k-1] - h[i]);
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}