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
  int n,m,X,Y;
  cin>>n>>m>>X>>Y;
  vin x(n),y(m);
  rep(i,0,n) cin>>x[i];
  rep(i,0,m) cin>>y[i];
  ///////////////
  bool war=0;
  sort(all(x));sort(all(y));
  reverse(all(x));
  if(x[0]>=y[0]) war=1;
  bool ok=false;
  rep(i,x[0]+1,y[0]+1){//i=z
    if(X<i&&i<=Y) ok=true;
  }
  if(!ok) war=1;
  
  //cout<<x[0]<<y[0]<<endl;
  if(war) cout<<"War"<<endl;
  else cout<<"No War"<<endl;
}