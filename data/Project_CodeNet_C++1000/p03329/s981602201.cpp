#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n;
  cin>>n;
  ll x=0;
  ///
  ll dp[100010];
  rep(i,100010) dp[i]=i;
  rep(i,100010){
   for(int pow6=6;pow6<=n;pow6*=6){
     if(i-pow6<0) break;
     chmin(dp[i],dp[i-pow6]+1);
   }
    for(int pow9=9;pow9<=n;pow9*=9){
     if(i-pow9<0) break;
     chmin(dp[i],dp[i-pow9]+1);
   }
    
  }//rep
  cout<<dp[n]<<endl;
}