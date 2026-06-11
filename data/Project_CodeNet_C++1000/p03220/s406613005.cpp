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
  double n,t,a;
  cin>>n>>t>>a;
  vector<double> h(n);
  rep(i,n) cin>>h[i];
  double ans=0,mn=inf;
  rep(i,n){
    if(abs(a-mn)>abs(a-t+h[i]*0.006)){
      ans=i;
      mn=t-h[i]*0.006;
      //cout<<mn<<endl;
    }
    
  }
  cout<<ans+1<<endl;
}





