//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  vl vec={0,2,5,5,4,5,6,3,7,6};
  ll n,m;cin>>n>>m;
  ll dp[10010];
  rep(i,10010)dp[i]=-INF;
  dp[0]=0;
  vl a(m);
  rep(i,m){
    cin>>a[i];
    rep(j,n+1){
      if(j<vec[a[i]])continue;
      dp[j]=max(dp[j],dp[j-vec[a[i]]]+1);
    }
  }
  ll num=dp[n];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll count=0;
  while(count<num&&n>0){
    rep(i,m){
      if(n-vec[a[i]]>=0&&dp[n]==dp[n-vec[a[i]]]+1){
        n-=vec[a[i]];
        count++;
        cout<<a[i];
        break;
      }
    }
  }
 // cout<<endl;
  //cout<<vec[1]<<" "<<vec[9]<<endl;

}