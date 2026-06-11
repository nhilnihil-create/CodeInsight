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

vec d,s;
ll N;

ll Solve(ll x){
    ll a=s[x]/2;
    ll b=(s[x]+s[N]+1)/2;
    ll A=lower_bound(ALL(s),a)-s.begin();
    if(abs(s[x]-2*s[A])>abs(s[x]-2*s[A-1])) A--;
    else if(A==x) A--;
    ll B=lower_bound(ALL(s),b)-s.begin();
    if(abs(s[x]+s[N]-2*s[B])>abs(s[x]+s[N]-2*s[B-1])) B--;
    else if(B==N) B--;
    vec aa(4);
    aa[0]=s[A]; aa[1]=s[x]-s[A]; aa[2]=s[B]-s[x]; aa[3]=s[N]-s[B];
    //rep(i,4) cout<<aa[i]<<' ';
    //cout<<':'<<x<<endl;
    sort(ALL(aa));
    return aa[3]-aa[0];

}

int main(){
    cin>>N;
    rep(i,N) {
        ll x; cin>>x;
        d.pb(x);
    }
    s.pb(0);
    rep(i,N) s.pb(s[i]+d[i]);
    ll ans=INF;
    REP(i,2,N-1) ans=min(ans,Solve(i));
    cout<<ans<<endl;
}