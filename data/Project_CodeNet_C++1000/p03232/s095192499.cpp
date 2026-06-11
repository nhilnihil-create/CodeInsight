#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}

vector<ll> pw2(51,1);vector<ll> pw10(19,1);
ll fac[500001],finv[500001],inv[500001];
 
void table() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(ll i=2;i<500001;i++){
        fac[i]= fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll dev(long long a,long long b){
    return (a*inv[b])%MOD;
}

ll comb(ll n, ll k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

ll perm(ll n,ll k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return (fac[k]*comb(n,k))%MOD;
}
int main(){
    table();
    {rep1(i,50) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N; cin>>N;
    ll ans=0;
    vector<ll> A(N+1,0);
    vector<ll> s(N+2,0);
    rep1(i,N){
      cin>>A[i];
      s[i+1]=s[i]+(fac[N]*inv[i])%MOD;
        s[i+1]%=MOD;
    }
    rep1(i,N){
        ll tmp_1=(s[i+1]-s[2]);
        ll tmp_2=(s[N-i+2]-s[1]);
        if(tmp_1<0) tmp_1+=MOD;
        if(tmp_2<0) tmp_2+=MOD;
        tmp_1%=MOD;
        tmp_2%=MOD;
        
        ans+=(A[i]*(tmp_1+tmp_2)%MOD)%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}

