#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 3e18+7
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

vector<vector<int>> G;
vector<int> color;

bool dfs(int v, int cur=0){
    color[v] = cur;
    for(auto nv:G[v]){
        if(color[nv]!=-1){
            if(color[nv]==cur) return false;
            continue;
        }
        if(!dfs(nv,1-cur)) return false;
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    G.resize(N);
    REP(i,M){
        int a,b;
        cin>>a>>b;
        --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    color.assign(N,-1);
    bool bipartite =true;
    REP(v,N){
        if(color[v]!=-1) continue;
        if(!dfs(v)) bipartite = false;
    }

    if(bipartite){
        ll b=0, w=0;
        REP(i,N) (color[i]? b++ : w++);
        cout<< b*w - M <<endl;
    }
    else{
        cout << (ll)N*(N-1)/2 - M << endl;
    }

}