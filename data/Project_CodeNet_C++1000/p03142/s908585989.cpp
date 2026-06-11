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
#define outs(x) cout << (x) << " "
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
vector<int> G[MAX];
int inv[MAX];


int main(){
    int n, m; cin >> n >> m;
    rep(i, n+m-1){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        inv[b]++;
    }

    int r; //root
    rep(i, n){
        if(inv[i] == 0){
            r = i; break;
        }
    }

    vector<int> par(n); par[r] = -1;
    queue<int> q; q.push(r);
    while(!q.empty()){
        int s = q.front(); q.pop();
        for(int t : G[s]){
            inv[t]--;
            if(inv[t] == 0){
                par[t] = s;
                q.push(t);
            }
        }
    }

    rep(i, n) out(par[i] + 1);
}