#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef pair<l_l,ll> lll;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ld dp[310][310][310];
ll sa,sb,sc;
ll n;
ld rec(ll a,ll b,ll c){
    if(dp[a][b][c]>=0)return dp[a][b][c];
    if(a==0&&b==0&&c==0) return 0.0;
    ld res=0.0;
    if(a!=0)res+=a*rec(a-1,b,c);
    if(b!=0)res+=b*rec(a+1,b-1,c);
    if(c!=0)res+=c*rec(a,b+1,c-1);
    res+=n;
    res*=1.0/(a+b+c);
    return dp[a][b][c]=res;
}
int main(){
    cin>>n;
    vl a(n);
    rep(i,n)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    sa=0,sb=0,sc=0;
    rep(i,n){
        if(a[i]==1)sa++;
        else if(a[i]==2)sb++;
        else sc++;
    }
    ld ans=rec(sa,sb,sc);
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}