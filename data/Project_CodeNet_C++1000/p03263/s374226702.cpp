#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;


int main(){
  int H, W; cin >> H >> W;
  int a[H][W];
  rep(row,H) rep(col,W) cin >> a[row][col];

  vector<tuple<int,int,int,int>> log; 
  
  rep(row,H){
    rep(col,W-1){
      if (a[row][col]%2) {
        --a[row][col];
        ++a[row][col+1];
        log.emplace_back(row+1,col+1,row+1,col+2);
      }
    }
  }
  rep(row,H-1){
    if (a[row][W-1]%2) {
      --a[row][W-1];
      ++a[row+1][W-1];
      log.emplace_back(row+1,W,row+2,W);
    }
  }

  cout << log.size() << endl;
  rep(i,(int)log.size()){
    cout << get<0>(log[i]) << " " << get<1>(log[i]) << " " << get<2>(log[i]) << " " << get<3>(log[i]) << endl;
  }


  // cout << fixed << setprecision(10);
  
  return 0;
}