//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

map<int,int> mp;
int dp[20010]; //作れる最大桁数

int main(){
  rep(j,20010) dp[j]=-inf;
  mp[1]=2;
  mp[2]=5;
  mp[3]=5;
  mp[4]=4;
  mp[5]=5;
  mp[6]=6;
  mp[7]=3;
  mp[8]=7;
  mp[9]=6;
  itn n,m; cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  dp[0]=0;
  rep(i,m)rep(j,20010){
    if(j+mp[a[i]]<20010) chmax(dp[j+mp[a[i]]],dp[j]+1);
  }
  //cout << dp[n] << endl;
  rsort(a);
  string ans;
  while(n){
    rep(i,m){
      if(n-mp[a[i]]>=0&&dp[n-mp[a[i]]]==dp[n]-1){
        ans+=to_string(a[i]);
        n=n-mp[a[i]];
        break;
      }
    }
  }
  cout << ans << endl;
}