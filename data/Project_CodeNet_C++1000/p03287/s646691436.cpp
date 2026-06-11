#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

void dump(vector<int> v) {
    string res = "@[";
    for (auto i : v) {
        res += to_string(i);
        res += ", ";
    }
    res += "]";
    cout << res << endl;
}

void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i] = a[i] % m;
    }
    map<int,int> ma;
    vector<int> acm(n+1);
    acm[0] = 0;
    rep(i,n) {
        acm[i+1] = acm[i] + a[i];
        acm[i+1] = acm[i+1] % m;
        ma[acm[i+1]] ++;
    }
    lint ans = 0;
    rep(i,n) {
        int t = acm[i] % m;
        ans += ma[t];
        ma[acm[i+1]] --;
        
    }
    //for (int i=1; i<n; i++) {
    //    if (a[i] == 0) ans ++;
    //}
    cout << ans << endl;

    // True
    /*
    lint anst = 0;
    for (int l=0; l<=n; l++) {
        for (int r=l+1; r<=n; r++) {
            if ((acm[r] - acm[l]) % m == 0) anst ++;
        }
    }
    cout << anst << endl;
    if (anst != ans) {
        cout << "false" << endl;
        cout << "n " << n << " m " << m << endl;
        dump(a);
    }
    */

}

int main() {
    solve();
}