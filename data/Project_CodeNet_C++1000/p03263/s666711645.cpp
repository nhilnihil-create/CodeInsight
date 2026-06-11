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
  int h,w;  cin >> h >> w;
  vector<vi> a(h,vi(w));  rep(i,h) rep(j,w) cin >> a[i][j];
  int ans = 0;
  vector<pair<int,int>> now,next;
  rep(i,h) rep(j,w){
    if(a[i][j]%2){
      if(j+1 < w){
        ans++;
        now.push_back({i+1,j+1});
        next.push_back({i+1,j+2});
        a[i][j+1] += a[i][j];
      }else{
        if(i+1 < h){
          ans++;
          now.push_back({i+1,j+1});
          next.push_back({i+2,j+1});
          a[i+1][j] += a[i][j];
        }
      }
    }
  }
  cout << ans << endl;
  rep(i,ans) cout << now[i].first <<" "<< now[i].second <<" " << next[i].first <<" "<< next[i].second << endl;
  cout << "\n";
  return 0;
}
