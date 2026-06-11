#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
using P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int h = 0,w = 0,d = 0;
  cin >> h >> w >> d;
  vector<P> point(h*w);
  rep(i,0,h){
    rep(j,0,w){
      int a;
      cin >> a;
      a--;
      point[a] = make_pair(i,j);
    }
  }
  vint ans(h*w);
  for(int i = 0;i < h*w;i++){
    if(i + d < h*w){
      ans[i + d] = ans[i] + abs(point[i+d].first - point[i].first) + abs(point[i+d].second - point[i].second);  
    }
  }
  int q = 0;
  cin >> q;
  rep(i,0,q){
    int a,b;
    cin >> a >> b;
    a--;b--;
    cout << ans[b] - ans[a] << endl;
  }
}