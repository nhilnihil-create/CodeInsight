#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair

bool ans=true;

const ll MaxN=100001;
vector<P> d[MaxN];

ll D[MaxN];
bool Used[MaxN];

void solve(ll y){
    Used[y]=true;
    ll K=d[y].size();
    if(K==0) return;
    if(!ans) return;
    rep(i,K){
        ll X=d[y].at(i).first, Y=d[y].at(i).second;
        if(D[Y]!=INF){
            if(D[Y]!=X+D[y]) {ans=false; return;}
        }
        else {
            D[Y]=X+D[y];
            solve(Y);
        }
        
    }
    //if(!ans) break;
    return;
}



int main(){
    ll N,M; cin>>N>>M;
    rep(i,MaxN) Used[i]=true;
    rep(i,MaxN) D[i]=INF;
    rep(i,M){
        ll L,R,DD; cin>>L>>R>>DD;
        Used[L]=false;
        Used[R]=false;
        d[L].pb(mp(DD,R));
        d[R].pb(mp(-DD,L));
    }
    rep(i,N+1) if(!Used[i]) {
        D[i]=0;
        solve(i);
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}