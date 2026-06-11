#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;

vector<vector<vector<ld>>> dp(301,vector<vector<ld>>(301,vector<ld>(301,-3)));
ld F(ll a, ll b, ll c,ld N){
    if(dp[a][b][c]>=0)return dp[a][b][c];
    if(a==0&&b==0&&c==0)return 0.0;
    ld ret=(N-a-b-c)/N;
    if(a>0)ret+=(((ld)a)/N)*(1.0+F(a-1,b+1,c,N));
    if(b>0)ret+=(((ld)b)/N)*(1.0+F(a,b-1,c+1,N));
    if(c>0)ret+=(((ld)c)/N)*(1.0+F(a,b,c-1,N));
    ret*=N/((ld)(a+b+c));
    return dp[a][b][c]=ret;
}


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N,0);
    for(ll i=0;i<N;++i)cin>>a[i];
    ll cou1=0,cou2=0,cou3=0;
    for(ll i=0;i<N;++i){
        if(a[i]==1)cou1++;
        if(a[i]==2)cou2++;
        if(a[i]==3)cou3++;
    }
    cout << fixed << setprecision(15);
    prt(F(cou3,cou2,cou1,(ld)N))


    return 0;
}
