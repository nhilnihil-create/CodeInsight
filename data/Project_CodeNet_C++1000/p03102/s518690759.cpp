#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n,m,c;
  cin>>n>>m>>c;
  vin b(m);
  rep(i,m) cin>>b[i];
  vector<vin> a(n,vin(m));
  rep(i,n){
    rep(j,m){
      cin>>a[i][j]; 
    }
  }
  //////
  int ans=0;
  rep(i,n){
   ll sum=0;
    rep(j,m)
    sum+=b[j]*a[i][j];
    
      if(sum+c>0) ans++;
    
  }
  
  cout<<ans<<endl;
}





