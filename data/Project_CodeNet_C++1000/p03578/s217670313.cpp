#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp1;
    rep(i, n) {
        int d;
        cin >> d;
        mp1[d]++;
    }
    int m;
    cin >> m;
    map<int, int> mp2;
    rep(i, m) {
        int t;
        cin >> t;
        mp2[t]++;
    }
    bool ans = true;
    for(auto x : mp2) {
        if(mp1[x.first] < x.second) ans = false;
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}