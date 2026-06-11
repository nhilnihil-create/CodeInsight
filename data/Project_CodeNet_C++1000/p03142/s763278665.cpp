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
template <typename T> bool chmax(T &a, T b) {if(a < b) {a = b;return 1;}return 0;}
template <typename T> bool chmin(T &a, T b) {if(a > b) {a = b;return 1;}return 0;}

int N,M;
ve<vi> G;
vi A;
int root = 0;
vi D;

int dfs(int n){
    
    if(D[n] >= 0) return D[n];
    
    if(A[n] == n) return D[n] = 0;
    if(A[n] != -1) return D[n] = dfs(A[n])+1;
    int res = 0;
    for (int p : G[n]) {
        int aa = dfs(p)+1;
        //cout << n csp p csp aa << endl;
        if(chmax(res,aa)){
            A[n] = p;
        }
    }
    
    return D[n] = res;
}


int main()
{
    cin >> N >> M;
    G.resize(N);
    D.assign(N,-1);
    rep(i,N+M-1){
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[b].pb(a);
    }
    A.assign(N,-1);
    rep(i,N){
        if(G[i].size() == 1){
            A[i] = G[i][0];
        }else if(G[i].size() == 0){
            A[i] = i;
            root = i;
        }
    }
    
    
    rep(i,N){
        if(A[i] == -1){
            dfs(i);
        }
    }
    
    
    rep(i,N) {
        if(A[i] == i) cout << 0 << endl;
        else cout << A[i]+1 << endl;
    }
    
    
    

    
    
    
    

    return 0;
}
