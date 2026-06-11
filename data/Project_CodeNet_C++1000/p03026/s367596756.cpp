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

vec d[10010];

int main(){
    ll N; cin>>N;
    rep(i,N-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        d[a].pb(b);
        d[b].pb(a);
    }
    vec c(N);
    rep(i,N) cin>>c[i];
    sort(ALL(c));
    reverse(ALL(c));
    ll ans=0;
    REP(i,1,N) ans+=c[i];
    queue<ll> Q;
    Q.push(0); ll j=1;
    vec ANS(N,-1);
    ANS[0]=c[0];
    while(!Q.empty()){
        ll A=Q.front();
        Q.pop();
        rep(i,d[A].size()){
            ll B=d[A][i];
            if(ANS[B]<0){
                ANS[B]=c[j];
                j++;
                Q.push(B);
            }
        }
    }
    cout<<ans<<endl;
    rep(i,N) cout<<ANS[i]<<' ';
    cout<<endl;


}