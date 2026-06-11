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

int n;
vector<int> to[MAX];

int tree_diameter(){
    int p;
    queue<P> q; q.push(P(0,-1));
    while(!q.empty()){
        P a = q.front(); q.pop(); p = a.fi;
        for(int b : to[a.fi]){
            if(b == a.se) continue;
            q.push(P(b, a.fi));
        }
    }
    vector<int> d(n);
    d[p]=0;  q.push(P(p,-1)); int ans = 0;
    while(!q.empty()){
        P a = q.front(); q.pop();
        for(int b : to[a.fi]){
            if(b == a.se) continue;
            d[b] = d[a.fi]+1;
            q.push(P(b, a.fi));
        }
        ans = max(ans, d[a.fi]);
    }
    return ans;
}

int main(){
    cin>>n;
    rep(i, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int dm = tree_diameter();
    if((dm+1) % 3 == 2) out("Second");
    else out("First");
}