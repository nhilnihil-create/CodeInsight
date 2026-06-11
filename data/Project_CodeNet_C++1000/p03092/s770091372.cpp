/*

  _|_|                              _|  _|    _|
_|    _|  _|  _|_|  _|_|_|_|        _|  _|  _|
_|    _|  _|_|          _|          _|  _|_|
_|    _|  _|          _|      _|    _|  _|  _|
  _|_|    _|        _|_|_|_|    _|_|    _|    _|

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
//#define ls (rt<<1)
//#define rs (rt<<1|1)
#define vi vector<int>
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define fi first
#define se second
typedef long long ll;
using namespace std;
const int maxn=5005;
int n,a,b;
ll dp[maxn];
int main(){
    ios::sync_with_stdio(0);
    memset(dp,0x3f,sizeof(dp));dp[0]=0;
    cin>>n>>a>>b;
    rep(i,1,n){
        int num;cin>>num;
        ll mi=1e18;
        rep(j,0,num)mi=min(mi,dp[j]);
        rep(j,0,num-1)dp[j]+=a;
        rep(j,num+1,n)dp[j]+=b;
        dp[num]=mi;
    }
    ll ans=1e18;
    rep(i,1,n)ans=min(ans,dp[i]);
    cout<<ans;
    return 0;
}