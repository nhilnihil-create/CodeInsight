#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 100005;

/* ...o(^-^)o... */

int main(){
    ii3(h, w, n); ii2(sr, sc); sr--; sc--;
    string s, t; cin >> s >> t;
    int u = 0, d = h, l = 0, r = w;
    repr(i, n){
        if(t[i]=='U') d = min(d+1, h);
        else if(t[i]=='D') u = max(u-1, 0);
        else if(t[i]=='L') r = min(r+1, w);
        else l = max(l-1, 0);

        if(s[i]=='U') u++;
        else if(s[i]=='D') d--;
        else if(s[i]=='L') l++;
        else r--;

        if(u >= d || l >= r){
            out("NO"); return 0;
        }
    }
    if(u <= sr && sr < d && l <= sc && sc < r){
        out("YES"); return 0;
    }
    out("NO");
}