#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

ll N; 
vec d;

bool ABLE(){
    rep(i,N) {
        if(d[i]>i) return false;
        if(i>0) if(d[i]>d[i-1]+1) return false;
    }
    return true;
}


int main(){
    cin>>N;
    rep(i,N){
        ll x; cin>>x;
        d.pb(x);
    }
    ll ans=0;
    if(!ABLE()) ans=-1;
    else{
        for(int i=N-1; i>=0; i--){
            if(i==N-1) ans+=d[i];
            else if(d[i]!=d[i+1]-1) ans+=d[i];
        }
    }
    cout<<ans<<endl;
}