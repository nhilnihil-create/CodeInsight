/**
*    created: 21.06.2020 02:57:51
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

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int l, r;
    vector<int> made(n);
    rep(i,n) {
        if (i >= 1 && s[i] == 'C' && s[i-1] == 'A') made[i]++;
    }
    rep2(i,1,n) made[i] += made[i-1];
    rep(i,q) {
        cin >> l >> r;
        // substr(l-1,r-l+1)
        cout << made[r-1] - made[l-1] << endl;
    }
    return 0;
}