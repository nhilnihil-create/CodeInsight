#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define INF 1e9
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair

int main(){
  int n; cin >> n;
  vector<pii> red(n), blue(n);
  rep(i, n){
    int a, b; cin >> a >> b;
    red[i] = mp(a, b);
  }
  rep(i, n){
    int c, d; cin >> c >> d;
    blue[i] = mp(c, d);
  }
  sort(all(red));
  sort(all(blue));

  int cnt = 0;
  rep(i, n){
    int c = blue[i].fi;
    int d = blue[i].se;
    int mj = -1;
    int mb = 0;
    rep(j, red.size()){
      int a = red[j].fi;
      int b = red[j].se;
      if(a<c && b<d){
        if(b >= mb){
          mb = b;
          mj = j; 
        }
      }
    }
    if(mj >= 0){
      red.erase(red.begin() + mj);
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
