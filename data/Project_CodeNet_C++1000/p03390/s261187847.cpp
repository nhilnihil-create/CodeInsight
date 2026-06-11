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
const ll INF=1e15;
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

const ll DEKAI=1e9+1;
int main(){
    ll Q; cin>>Q;
    vec ans;
    rep(i,Q){
        ll a,b; cin>>a>>b;
        if(a>b) swap(a,b);
        ll K=a*b;
        K--;
        ll BIG=DEKAI,SMALL=0;
        while(BIG>SMALL+1){
            ll MID=(BIG+SMALL)/2;
            if(MID*MID<=K) SMALL=MID;
            else BIG=MID;
        }
        ll X=2*SMALL;
        if(SMALL*(SMALL+1)>K) X--;
        if(SMALL>=a) ans.pb(X-1);
        else ans.pb(X);

    }
    rep(i,Q) cout<<ans[i]<<endl;
}