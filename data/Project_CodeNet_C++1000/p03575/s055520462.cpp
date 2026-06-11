#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define uint unsigned int
#define ull  unsigned long long
#define pb push_back
#define mk make_pair
#define ins insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define X first
#define Y second
#define umap unordered_map
#define speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define setvalue(d,s,e,n) for(int qwe = s; qwe < e; ++qwe) d[qwe] = n
#define mset multiset
#define pqueue priority_queue
   
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
        
const int  N = 2e5 + 314;
const int INF = 1e9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const long long LINF = 1e18 + 3141;
set <int> g[N];
vector <pair <int,int> > M;
bool used[N];
int n, m;

void dfs(int v) {
    used[v] = 1;
    for(int f : g[v])
        if(!used[f])
            dfs(f);
}
bool check() {
    bool cnt = 1;
    for(int i = 1; i <= n; ++i)
        cnt &= used[i];
    return cnt;
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        M.pb({a, b});
        g[a].ins(b);
        g[b].ins(a);
    }
    int ans = 0;

    for(auto cur : M){
        for(int i = 1; i <= n; ++i)
            used[i] = 0;
        g[cur.X].erase(cur.Y);
        g[cur.Y].erase(cur.X);
        dfs(1);
        ans += check();
        g[cur.X].ins(cur.Y);
        g[cur.Y].ins(cur.X);
    }
    cout << m - ans;
}
 
int main(){
    speed();
    int t = 1;
    // cin >> t;
    while(t--)solve();
}