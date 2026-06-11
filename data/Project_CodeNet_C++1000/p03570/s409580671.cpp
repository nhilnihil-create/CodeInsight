#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

int pre[1<<26];

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    rep(i,(1<<26)) pre[i]=-1;
    pre[0]=0;
    
    string s;cin>>s;
    int n=(int)s.size();

    int dp[n+1];
    rep(i,n+1)dp[i]=INF;
    dp[0]=0;

    int bit=0;
    rep(i,n){
        int c=s[i]-'a';
        bit^=(1<<c);
        if(__builtin_popcount(bit)<=1) dp[i+1]=0;
        else{
            if(pre[bit]>=0) chmin(dp[i+1],dp[pre[bit]]+1);
            rep(j,26){
                if(pre[bit^(1<<j)]>=0) chmin(dp[i+1],dp[pre[bit^(1<<j)]]+1);
            }        
        }
        pre[bit]=i+1;
    }
    cout<<dp[n]+1<<endl;
    return 0;
}
