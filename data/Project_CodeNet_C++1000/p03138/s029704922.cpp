#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[14][2];

int main(){
  ll n,k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  int mxi=0;
  ll K=k;
  while(K>0){
    K/=2;
    mxi++;
  }mxi--;
  ll ans=0;
  bool miman=0;
  for(int i=mxi;i>=0;i--){
    int cnt1=0;
    rep(j,n){
      if((1ll<<i)&a[j]) cnt1++;
    }
    if(cnt1<n-cnt1&&((k&(1ll<<i))||miman)){
      ans+=(1ll<<i)*(n-cnt1);
    }
    else if(cnt1>=n-cnt1&&(k&(1ll<<i))){
      miman=1;
      ans+=(1ll<<i)*cnt1;
    }
    else{
      ans+=(1ll<<i)*cnt1;
    }
  }
  rep(j,n){
    for(int i=mxi+1;i<=40;i++){
      ans+=a[j]&(1ll<<i);
    }
  }
  cout << ans << endl;
}