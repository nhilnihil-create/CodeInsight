#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P> > P_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double PI=3.1415926535897932;
const double LIT=0.000000000001;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod
#define MUL(a,b) a=(a*b)%mod

vec d(110,0);




vec Sosu;

void yaku(ll a){
    ll A=a;
    int i=0;
    while(true){
        ll k=Sosu[i];
        if(k*k>A) break;
        if(!(A%k)){
            ll Count=0;
            while(true){
                if(A%k) break;
                Count++;
                A/=k;
            }
            d[k]+=Count;
        }
        i++;
    }
    if(A==1) return;
    d[A]++;
    return;
}

int main(){
    ll N; cin>>N;
    Sosu.pb(2);
    Sosu.pb(3);
    Sosu.pb(5);
    Sosu.pb(7);
    Sosu.pb(11);
    REP(i,2,N+1) yaku(i);
    ll A=0, B=0,C=0,D=0,E=0;
    REP(i,2,N+1){
        //cout<<i<<' '<<d[i]<<endl;
        if(d[i]>=4) A++;
        else if(d[i]>=2) B++;
        if(d[i]>=14) C++;
        if(d[i]>=24) D++;
        if(d[i]>=74) E++;
    }
    ll ans=0;
    ans+=A*(A-1)*(A-2)/2;
    ans+=B*A*(A-1)/2;
    ans+=C*(A-1);
    ans+=D*(A+B-1);
    ans+=E;
    cout<<ans<<endl;

}