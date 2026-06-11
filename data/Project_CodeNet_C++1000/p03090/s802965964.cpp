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
    ii(n);
    if(n == 3){
        out(2); out("1 3"); out("2 3"); return 0;
    }
    
    bool f = n % 2; if(f) n--;
    vector<P> ans;
    for(int i = 1; i < n/2; i++){
        for(int j = i+1; j <= n-i; j++){
            ans.push_back(P(i, j));
            ans.push_back(P(j, n-i+1));
        }
    }
    if(f){
        for(int i = 1; i <= n; i++) ans.push_back(P(i, n+1));
    }

    out(ans.size());
    rep(i, ans.size()){
        out(to_string(ans[i].fi) + " " + to_string(ans[i].se));
    }
}
