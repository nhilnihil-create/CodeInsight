#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for (Int i = s; i < (Int)(n); i++)
#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
double EPS = 1e-10;
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int n;
    cin >> n;
    string s, t, r;
    cin >> s >> t >> r;
    Int res = 0;
    rep(i, 0, n) {
        map<char, Int> mp;
        mp[s[i]]++;
        mp[t[i]]++;
        mp[r[i]]++;
        res += mp.size() - 1;
    }
    dump(res);
    return 0;
}