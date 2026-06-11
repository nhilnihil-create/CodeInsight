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
typedef vector<string> vs;
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
ll n;
ld dp[330][330][330];
ld rec(ll a,ll b,ll c){
    if(dp[a][b][c]>=0)return dp[a][b][c];
    if(a==0&&b==0&&c==0)return dp[0][0][0]=0.0;
    ld res=n;
    if(a-1>=0)res+=rec(a-1,b,c)*a;
    if(b-1>=0)res+=rec(a+1,b-1,c)*b;
    if(c-1>=0)res+=rec(a,b+1,c-1)*c;
    res/=a+b+c;
    return dp[a][b][c]=res;
}
int main(){
    cin>>n;
    ll a=0,b=0,c=0;
    memset(dp,-1,sizeof(dp));
    rep(i,n){
        ll x;cin>>x;
        if(x==1)a++;
        else if(x==2)b++;
        else c++;
    }
    ld ans=rec(a,b,c);
    cout.precision(20);
    cout<<ans<<endl;
    return 0;
}