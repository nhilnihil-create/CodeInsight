// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll power(ll x, ll y); 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_dedges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B);}
#define in_wedges(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C), v[B].pb(A, C);}
#define in_dwedges(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C);}
#define endl "\n"

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 18;
const int inf = 2e9;

const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
vector<int> sink;

void dfs(int s){
    vis[s] = 1;
    for(auto i: v[s]) if(!vis[i]) dfs(i);
    sink.pb(s);
}
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    quickio
    int n, m;
    cin >> n >> m;
    in_dedges(m);

    repp(i, 1, n) if(!vis[i]) dfs(i);
    reverse(all(sink));
    vector<int> dis(n + 1, 0);

    for(auto i : sink) for(auto j : v[i]) dis[j] = max(dis[j], dis[i] + 1);
    cout << *max_element(all(dis));
}

ll power(ll x, ll y){ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}