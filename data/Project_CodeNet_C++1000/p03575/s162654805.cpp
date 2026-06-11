#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;

//int use[250];
vector<pair<int,int>> L;
int visited[55];
vector<int> to[51];

void dfs(int u){
    visited[u]=1;
    for(int v:to[u]){
        if(visited[v]==0){
            dfs(v);
        }
    }
    visited[u]=2;
    return;
}

int main(){
    int n,m;
    int ans=0;
    cin >> n>> m;
    rep(i,m){
        int a,b;
        cin >> a>> b;
        a--;b--;
        L.push_back(mp(a,b));
    }
    rep(i,m){
        rep(j,n){
            visited[j]=0;
            to[j].clear();
        }
        for(int j=0;j<m;j++){
            if(j!=i){
                int a=L[j].fi;
                int b=L[j].se;
                to[a].push_back(b);
                to[b].push_back(a);
            }
        }
        dfs(0);
        bool connect=1;
        rep(j,n){
            //cerr<<visited[j]<<' ';
            if(visited[j]==0){
                connect=0;
            }
        }
        //cerr<<endl;
        if(connect!=1){
            //cerr<<L[i].fi+1<<' '<<L[i].se+1<<endl;
            ans++;
        }
        //cerr<<endl;
    }
    cout<<ans<<endl;
    return 0;
}