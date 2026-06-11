#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repp(i, n, m) for(int (i) = (n); (i) < (m); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define ldou long double
#define fi first
#define se second
#define setpre(x) std::cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ std::cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , "; logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 200005;

/* ...o(^-^)o... */

int n, q;
string s;
char vq[MAX][2];

int solve(int i){
    rep(j,q){
        if(s[i]!=vq[j][0]) continue;
        if(vq[j][1]=='L') i--;
        else i++;
        if(i<0||i>=n) return i;
    }
    return i;
}

int main(){
    cin>>n>>q>>s;
    rep(i, q) cin>>vq[i][0]>>vq[i][1];

    int ok=-1, ng=n;
    while(ng-ok>1){
        int mid=(ok+ng)/2;
        if(solve(mid)<0) ok=mid;
        else ng=mid;
    }
    int ans=ok+1;

    ng=-1, ok=n;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        if(solve(mid)>=n) ok=mid;
        else ng=mid;
    }
    ans+=n-ok;
    out(n-ans);
}
