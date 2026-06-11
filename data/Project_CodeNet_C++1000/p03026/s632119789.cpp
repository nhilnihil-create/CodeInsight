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
const int MAX = 10005;

/* ...o(^-^)o... */
vector<int> to[MAX];

int main(){
    int n; cin >> n;

    rep(i, n-1){
        int a, b; cin >> a >> b; a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<lint> c(n);
    rep(i, n) cin >> c[i];
    sort(all(c), greater<lint>());

    vector<lint> ans(n);
    queue<int> bfs; bfs.push(0);
    bool seen[MAX]; fill(seen, seen + n, false); int j = 0;
    while(!bfs.empty()){
        int s = bfs.front(); bfs.pop();
        seen[s] = true; ans[s] = c[j]; j++;
        for(int& t: to[s]){
            if(seen[t]) continue;
            bfs.push(t);
        }
    }

    lint m = 0;
    rep(i, n-1) m += c[i+1];
    
    out(m);
    rep(i, n) outs(ans[i]);
    out("");
}