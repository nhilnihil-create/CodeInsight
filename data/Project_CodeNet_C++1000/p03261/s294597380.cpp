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
 int n;
  cin>>n;
  vector<string> w(n);
  rep(i,0,n) cin>>w[i];
  map<string,int> g;
  bool ok=true;
  char end=w[0][w[0].size()-1];
  g[w[0]]++;
  rep(i,0,n-1){
    if(w[i][w[i].size()-1]!=w[i+1][0]) ok=false;
    else{
      if(g[w[i+1]]>0) ok=false;
      g[w[i+1]]++;
    }
  }
  if(ok){
    cout<<"Yes" <<endl;
  }
  else cout<< "No" <<endl;
}






