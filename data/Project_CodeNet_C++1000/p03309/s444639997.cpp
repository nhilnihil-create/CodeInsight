#include <iostream>
#include<string>
#include<cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<stack>
#include<set>
#include <limits>
#include <climits>
#include <numeric>
#include<cassert>
using namespace std;
typedef long long ll;
typedef vector<ll>VI;
typedef vector<bool>VB;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define bitrep(bit,A) for(int bit=A; ;bit=(bit-1)&A)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) (ll)((a).size())
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define SORT(c) stable_sort(ALL(c))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
#define MOD 1000000007
#define INF 1<<30
#define INFTY 1000000000000000001LL
#define MAX_INT INT_MAX
#define Endl '\n'
#define mian() main()
#define greater greater<int>()
VI findAll(string S,string pattern){VI P;ll pos=(ll)S.find(pattern);
while(pos!=string::npos){P.push_back(pos);pos=(ll)S.find(pattern,pos+1);}return P;}
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
bool is_prime(ll n){if(n<2)return 0;for(int i=2;i*i<n;i++)if(n%i==0)return 0;return 1;}
inline void eratosthenes(VB& p){rep(i,SZ(p))p[i]=1;p[0]=p[1]=0;
rep(i,SZ(p)/2+1){if(p[i])for(ll j=i+i;j<SZ(p);j+=i)p[j]=0;}}
inline ll mod_add(ll a,ll b){return (a+b)%MOD;}
inline ll mod_sub(ll a,ll b){return (a+MOD-b)%MOD;}
inline ll mod_mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
inline ll mod_pow(ll x,ll n,ll mod=(ll)MOD){ll res=1;while(n>0){
if(n&1)res=res*x%mod;x=x*x%mod;n>>=1;}return res;}
inline ll mod_inv(ll x){return mod_pow(x,MOD-2);}
inline ll mod_div(ll a, ll b){return mod_mul(a,mod_inv(b));}
using Graph=vector<vector<P> >;
ll median(ll n,ll a[]){
    return (!(n%2)?(a[n/2]+a[n/2-1])/2:a[n/2]);
}
int main(){
    ll n;ll a[MAX2];cin>>n;rep(i,n){cin>>a[i];a[i]-=i+1;}
    sort(a,a+n);
    ll b=median(n,a);
    ll ans=0;
    rep(i,n){
        ans+=abs(a[i]-b);
    }
    cout<<ans<<endl;
}