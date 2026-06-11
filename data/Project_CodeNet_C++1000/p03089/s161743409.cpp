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
const int MAX = 300005;

/* ...o(^-^)o... */

int n;
vector<int> b;
vector<bool> removed;
vector<int> ans;

bool dfs(int m){
    int j = -1;
    rep(i, n){
        if(removed[i]) continue;
        j++; if(b[i] > j) return false;
    }
    if(m == 1){
        ans.push_back(0);
        return true;
    }

    j = -1;
    rep(i, n){
        if(removed[i]) continue;
        j++; if(b[i] != j) continue;
        removed[i] = true;
        if(dfs(m - 1)){
            ans.push_back(i);
            return true;
        }
        removed[i] = false;
    }
    return false;
}

int main(){
    cin >> n;
    b = vector<int>(n);
    rep(i, n){
        cin >> b[i]; b[i]--;
    }
    removed = vector<bool>(n, false);
    if(!dfs(n)){
        out(-1); return 0;
    }
    rep(i, n) out(b[ans[i]]+1);
}