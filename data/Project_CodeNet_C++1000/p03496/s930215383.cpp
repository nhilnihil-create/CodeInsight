#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sort(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll mxabs=0;
  int mxabsi=0;
  bool pls=1;
  vector<pii> ans(0);
  rep(i,n){
    if(mxabs<abs(a[i])){
      chmax(mxabs,abs(a[i]));
      mxabsi=i;
      if(a[i]<0) pls=0;
      else pls=1;
    }
  }
  rep(i,n){
    if(pls){
      if(a[i]<0){
        a[i]=a[i]+mxabs;
        ans.push_back(pii(mxabsi,i));
      }
    }
    else{
      if(a[i]>0){
        a[i]=a[i]-mxabs;
        ans.push_back(pii(mxabsi,i));
      }
    }
  }
  if(pls){
    for(int i=0;i<n-1;i++){
      ans.push_back(pii(i,i+1));
    }
  }
  else{
    for(int i=n-1;i>0;i--){
      ans.push_back(pii(i,i-1));
    }
  }
  cout << ans.size() << endl;
  rep(i,ans.size()){
    cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
  }
}