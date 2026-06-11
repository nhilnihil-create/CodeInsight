#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;


int main(){
  int n,C;
  cin >> n >> C;
  vector<vector<P>> d(32);
  rep(i,n){
    int s,t,c; cin >> s >> t >> c;
    d[c].push_back({s,t});
  }
  rep(i,32){
    sort(d[i].begin(),d[i].end());
  }
  vector<vector<int>> ch(32, vector<int>(mx,0));
  rep(i,32){
    int m = d[i].size();
    rep(j,m){
      if(j>0 && d[i][j-1].S==d[i][j].F){
        ch[i][d[i][j-1].S*2] = 0;
      } else {
        ch[i][d[i][j].F*2-1] = 1;
      }
      ch[i][d[i][j].S*2] = -1;
    }
  }
  rep(i,32){
    rep(j,mx-1){
      ch[i][j+1] += ch[i][j];
    }
  }

  int ans = 0;
  rep(j,mx){
    int cnt = 0;
    rep(i,32){
      if(ch[i][j]) cnt++;
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}