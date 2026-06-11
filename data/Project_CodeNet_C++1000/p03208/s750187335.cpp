/**
*    created: 20.06.2020 02:58:17
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    sort(h.begin(),h.end());
    int mn = 10000000000;
    rep(i,n-k+1) mn = min(mn,h[i+k-1]-h[i]);
    cout << mn << endl;
    return 0;
}