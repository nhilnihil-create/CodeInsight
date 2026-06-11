/**
*    created: 26.06.2020 17:39:58
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
    
    auto ctoi = [&] (char c) {
        if (c >= '0' && c <= '9') return c - '0';
	    return -1;
    };

    string s;
    cin >> s;
    int k;
    cin >> k;
    int l = min(k,(long long)s.size());
    rep(i,l) {
        int a = ctoi(s[i]);
        if (a == 1) continue;
        else {
            cout << a << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}