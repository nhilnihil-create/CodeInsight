#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep (i, n) cin >> h[i];
    sort(ALL(h));
    int ans=1e9;
    rep(i, n-k+1) {
        int tmp = h[i+k-1] - h[i];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}