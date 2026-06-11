#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int x;
  cin>>x;
  int ans=0;
  rep(i,1,40){
    int cnt=0;
    rep(j,2,12){
      if(pow(i,j)<=x){
        cnt=pow(i,j); 
         ans=max(ans,cnt); 
      }
      else{
       ans=max(ans,cnt); 
        
      }
    }
  }
 // cout<<pow(1,2)<<endl;
  cout<<ans<<endl;
}