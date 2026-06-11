/**
*    created: 24.06.2020 13:29:49
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    vector<int> ans;
    int l = 0;
    int r = l + k - 1;
    rep(l, n - k + 1) {
        int r = l + k - 1;
        int tmp = min(abs(x[r])+abs(x[r]-x[l]),abs(x[l])+abs(x[r]-x[l]));
        ans.push_back(tmp);
    }
    sort(all(ans));
    cout << ans[0] << endl;
    return 0;
}