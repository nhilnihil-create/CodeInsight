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

ll N; vec d;
const int K=100;
ll x[K];

void keta(ll a, ll MID){
    if(!a) return;
    if(x[a]>MID) {
        x[a]=1;
        x[a-1]++;
        keta(a-1,MID);
    }
    return;
}
ll Solve(){
    bool UP=true;
    rep(i,N-1) if(d[i+1]<=d[i]) UP=false;
    if(UP) return 1;
    rep(i,N) if(d[i]>K-30) d[i]=K;
    ll NG=1, OK=N;
    while(OK>NG+1){
        ll MID=(NG+OK)/2;
        rep(i,K) {
            if(i<d[0]) x[i]=1;
            else x[i]=0;
        }
        REP(i,1,N){
            if(d[i]>d[i-1]) REP(j,d[i-1],d[i]) x[j]=1;
            else{
                if(d[i]<d[i-1]) REP(j,d[i],d[i-1]) x[j]=0;
                x[d[i]-1]++;
                keta(d[i]-1,MID);
            }
            /*if(MID==2 && i>=187731-K && i<187735){
                cout<<d[i]<<';';
                rep(i,K) cout<<x[i];
                cout<<endl;
            }*/
        }
        /*cout<<MID<<';';
        rep(i,K) cout<<x[i];
        cout<<endl;*/
        if(x[0]>MID) NG=MID;
        else OK=MID;
    }
    return OK;

}

void input(){
    cin>>N;
    rep(i,N){
        ll x; cin>>x;
        d.pb(x);
    }
}
int main(){
    /*N=199999;
    rep(i,187731) d.pb(187731-i);
    rep(i,N-187731) d.pb(187731-i);*/
    input();
    cout<<Solve()<<endl;
    

}