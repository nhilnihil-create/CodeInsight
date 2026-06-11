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
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);
ll mod_pow(ll x,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
ll high_order_bit(ll n){
    ll tmp=1,i=-1;
    while(tmp<=n){
        tmp*=2;
        i++;
    }
    if(n==0) return 0;
    else return i;
}
// 6 -> vec[0] [1] [2]
//          0   1   1
//vec[i]:2^iの位
vector<ll> binary_expansion(ll n){
    vector<ll> B(high_order_bit(n)+1);
    ll tmp=n;
    for(ll i=high_order_bit(n);i>=0;i--){
        B[i]=tmp/pw2[i];
        tmp%=pw2[i];
    }
    return B;
}

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,C; cin>>N>>C;
    vector<vector<ll> > D(C+1,vector<ll>(C+1,0));
    vector<vector<ll> > c(N,vector<ll>(N,0));
    rep1(i,C)rep1(j,C) cin>>D[i][j];
    rep(i,N)rep(j,N) cin>>c[i][j];
    
    //cost[i][j]:あまりiを色jに変えるコスト
    vector<vector<ll> > cost(3,vector<ll>(31,0));
    
    rep(i,3)rep1(j,C){
        ll tmp=0;
        rep(x,N)rep(y,N){
            if((x+y)%3==i && c[x][y]!=j) tmp+=D[c[x][y]][j];
        }
        cost[i][j]=tmp;
    }
    
    ll ans=INF;
    rep1(i,C)rep1(j,C)rep1(k,C){
        if(i!=j && j!=k && k!=i){
            chmin(ans,cost[0][i]+cost[1][j]+cost[2][k]);
        }
    }
    cout<<ans<<endl;
}
