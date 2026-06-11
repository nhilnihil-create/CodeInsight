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
int x[4],y[4];
  cin>>x[0]>>y[0]>>x[1]>>y[1];
  int a=(y[1]-y[0]);
  int b=(x[1]-x[0]);
 // cout<<b<<endl;
  x[2]=x[1]-a;
  y[2]=y[1]+b;
  x[3]=x[2]-b;
  y[3]=y[2]-a;
  rep(i,2,4){
   cout<<x[i]<<" "<<y[i]<<" "; 
  }
  cout<<endl;
}








