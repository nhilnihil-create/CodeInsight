#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd>> Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-3;
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
#define CHECK cout<<"arrived"<<endl

vec d;
ll N,Q;
vector<P> x;

ll Solve(ll a, ll i){
    if(i==Q) return a;
    if(a==0) return 0;
    if(a==N+1) return N+1;
    if(d[a]!=x[i].first) return Solve(a,i+1);
    return Solve(a+x[i].second,i+1);
}

int main(){
    cin>>N>>Q;
    string S; cin>>S;
    d.pb(26);
    rep(i,N) d.pb(S[i]-'A');
    d.pb(26);
    ll ans=0;
    rep(i,Q){
        char a,b; cin>>a>>b;
        if(b=='R') x.pb(mp(a-'A',1));
        else x.pb(mp(a-'A',-1));
    }
    //CHECK;

    ll OK=0, NG=N+1;
    while(NG>OK+1){
        ll MID=(NG+OK)/2;
        if(Solve(MID,0)==0) OK=MID;
        else NG=MID;
    }
    ans+=OK;
    //cout<<OK<<endl;
    OK=N+1, NG=0;
    while(OK>NG+1){
        ll MID=(NG+OK)/2;
        if(Solve(MID,0)==N+1) OK=MID;
        else NG=MID;
    }
    //cout<<(N+1-OK)<<endl;
    ans+=(N+1-OK);
    cout<<N-ans<<endl;


    

}