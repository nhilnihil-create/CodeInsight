#include "bits/stdc++.h"
using namespace std;

#define Rep(i,n) for(int i=0;i<n;i++)
#define For(i,n1,n2) for(int i=n1;i<n2;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define RREP(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define put(a) cout<<a<<"\n";
#define all(c)  (c).begin(),(c).end()
#define SORT(a) sort((a).begin(),(a).end())
#define TDARRAY(int,a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()

typedef long long ll;
typedef pair<int, int> P;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return 1;}return 0;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b){a=b;return 1;}return 0;}

struct edge{
    int to;
};

int n,m;
vector<vector<edge>> e;
vector<int> c;

bool dfs(int a,int color){
    c[a]=color;
    REP(i,e[a].size()){
        if(c[e[a][i].to]==color){
            return false;
        }
        if(c[e[a][i].to]==-1&&!dfs(e[a][i].to,1-color)){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    e.resize(n);
    REP(i,m){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        edge ed1;
        ed1.to = b[i];
        e[a[i]].push_back(ed1);
        edge ed2;
        ed2.to = a[i];
        e[b[i]].push_back(ed2);
    }
    c.resize(n);
    fill(all(c),-1);
    if(dfs(a[0],0)){
        int cw=0,cb=0;
        REP(i,n){
            if(c[i]==0){
                cw++;
            }else if(c[i]==1){
                cb++;
            }
        }
        put((ll)cw*cb-m);
    }else{
        put((ll)n*(n-1)/2-m);
    }
    return 0;
}
