/**
*    created: 21.06.2020 02:52:49
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

    int n, x;
    cin >> n >> x;
    vector<int> p;
    rep(i,n) {
        int tmp;
        cin >> tmp;
        p.push_back(abs(tmp-x));
    }
    int d = p[0];
    rep(i,n-1) {
        d = __gcd(d,p[i+1]);
    }
    cout << d << endl;
    return 0;
}