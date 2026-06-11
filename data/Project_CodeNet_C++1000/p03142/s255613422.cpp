#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e18;
const double PI=3.1415926535897932;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod

vec d[100010];

int main(){
    ll N,M; cin>>N>>M;
    vec used(N,0);
    rep(i,N+M-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        d[a].pb(b);
        used[b]++;
    }
    ll Oya;
    rep(i,N) if(!used[i]) Oya=i;
    vec ans(N,-INF);
    ans[Oya]=-1;
    queue<ll> Q;
    Q.push(Oya);
    while(!Q.empty()){
        ll x=Q.front();
        Q.pop();
        rep(i,d[x].size()){
            ll A=d[x][i];
            used[A]--;
            if(!used[A]){
                ans[A]=x;
                Q.push(A);
            }
        }
    }
    rep(i,N) cout<<ans[i]+1<<endl;

}