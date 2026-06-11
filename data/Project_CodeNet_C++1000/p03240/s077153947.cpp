#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi x(n),y(n),h(n);
  tuple<int,int,int> t;
  rep(i,n){
    cin >> x[i] >> y[i] >> h[i];
    if(0 < h[i]) t = make_tuple(x[i],y[i],h[i]);
  }

  int ans_x = -1, ans_y = -1, ans_h = -1;
  rep(i,101){
    rep(j,101){
      int candidate = get<2>(t)+abs(j-get<0>(t))+abs(i-get<1>(t));
      bool ok = true;
      rep(k,n) if(h[k] != max(0,candidate-abs(j-x[k])-abs(i-y[k]))) ok = false;
      if(ok){
        ans_h = candidate;
        ans_x = j;
        ans_y = i;
      }
    }
  }
  cout << ans_x << " " << ans_y << " " << ans_h;
  cout << "\n";
  return 0;
}
