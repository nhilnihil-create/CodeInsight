#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;
template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b;return 1;}return 0;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b;return 1;}return 0;}

int N,M;
vvi G;
vi color;

bool dfs(int u, int v, int c){
    color[u] = c;
    for (int p : G[u]) {
        
        
        if(color[p] != -1){
            if(color[p] == c) return false;
            continue;
        }
        
        if(!dfs(p,u,1-c)) return false;
        
    }
    
    return true;
    
}

int main(){

    cin >> N >> M;
    G.resize(N);
    color.assign(N,-1);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    
    if(dfs(0,-1,0)){
        int o = 0;
        rep(i,N){
            if(color[i]) o++;
        }

        cout << (ll)o*(ll)(N-o)-(ll)M << endl;
    }else{
        cout << (ll)(N)*(ll)(N-1)/2-(ll)(M) << endl;
    }
    
    

    return 0;
}
