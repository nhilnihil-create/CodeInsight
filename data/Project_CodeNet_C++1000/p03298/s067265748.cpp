#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef complex<double> xy_t;
const lint mod = 1e9 + 7;

int main(){
    int n;
    string s;
    cin >> n >> s;
    map<pss, lint> mp;
    string t = s.substr(n, n);
    reverse(t.begin(), t.end());
    rep(i, 1<<n){
        string u = "";
        string v = "";
        rep(j, n){
            if((i>>j) & 1) u += t[j];
            else v += t[j];
        }
        ++mp[pss(u, v)];
    }
    lint ans = 0;
    rep(i, 1<<n){
        string u = "";
        string v = "";
        rep(j, n){
            if((i>>j) & 1) u += s[j];
            else v += s[j];
        }
        ans += mp[pss(u, v)];
    }
    printf("%lld\n", ans);
}