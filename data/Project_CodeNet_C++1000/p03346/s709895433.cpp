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
const int MAX = 200005;

/* ...o(^-^)o... */
bool ok[MAX], seen[MAX];
int dfs(int s){
    seen[s] = true; int res = 1;
    if(ok[s]) res += dfs(s + 1);
    return res;
}

int main(){
    int n; cin >> n; vector<int> vec(n), inv(n);
    rep(i, n){
        int p; cin >> p; p--;
        vec[i] = p; inv[p] = i;
    }

    rep(i, n-1){
        if(inv[i] < inv[i+1]) ok[i] = true;
    }

    int ans = 1;
    rep(i, n-1){
        if(seen[i]) continue;
        ans = max(ans, dfs(i));
    }
    out(n - ans);
}