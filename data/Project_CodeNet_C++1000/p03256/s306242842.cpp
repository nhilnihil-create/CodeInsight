#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; string S; cin >> N >> M >> S;
    vector<vector<int>> G(N);
    rep(i,M){
        int a,b; cin >> a >> b; --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<vector<int>> cnt(N,vector<int>(2,0));
    queue<int> que;
    set<int> erased;
    rep(v,N){
        for (auto nv:G[v]){
            if (S[nv]=='A') ++cnt[v][0];
            else ++cnt[v][1];
        }
        if (!cnt[v][0]||!cnt[v][1]) que.push(v),erased.insert(v);
    }
    while(!que.empty()){
        int v=que.front(); que.pop();
        int i=S[v]=='A'?0:1;
        for (auto nv:G[v]){
            if (erased.count(nv)) continue;
            --cnt[nv][i];
            if (cnt[nv][i]==0) que.push(nv),erased.insert(nv);
        }
    }
    if (erased.size()==N) cout << "No" << endl;
    else cout << "Yes" << endl;
}