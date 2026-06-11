#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef multiset<ll> S;
typedef priority_queue<ll> PQ;
typedef priority_queue<P,vector<P>,greater<P>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double pi=3.14159265358979323846;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
void outvi(vi v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
void outvvi(vvi v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}
int main(){
    string s;cin>>s;
    ll n=s.size();
    vvi dp(n,vi(4));
    dp[0][3]=1;
    rep(i,n){
        if(i){
            rep(j,4)dp[i][j]=dp[i-1][j];
            if(s[i]=='?')rep(j,4)dp[i][j]*=3;
            if(s[i]=='A'||s[i]=='?')dp[i][0]+=dp[i-1][3];
            if(s[i]=='B'||s[i]=='?')dp[i][1]+=dp[i-1][0];
            if(s[i]=='C'||s[i]=='?')dp[i][2]+=dp[i-1][1];
        }
        else if(s[i]=='A'||s[i]=='?')dp[i][0]++;
        if(i==0&&s[i]=='?')dp[i][3]*=3;
        rep(j,4)dp[i][j]%=mod;
    }
    cout<<dp[n-1][2]<<endl;
}