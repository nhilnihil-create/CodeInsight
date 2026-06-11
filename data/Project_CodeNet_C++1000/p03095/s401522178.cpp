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
    string s;
    cin >> s;
    map<char, Int> mp;
    rep(i, 0, n) mp[s[i]]++;
    Int res = 1;
    for (auto i : mp) {
        res *= i.se + 1;
        res %= mod;
    }
    dump(res - 1);
    return 0;
}