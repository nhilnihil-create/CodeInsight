#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

string angle = "RLUD";
ll vx[4] = {1,-1,0,0};
ll vy[4] = {0,0,1,-1};

void solve(const vector<ll>& w, ll x, ll y){
  ll nx = 0, ny = 0;
  rep(i,w.size()){
    ll len = w[i];
    ll mindist = 1e18;
    int mink = -1;
    rep(k,4){
      ll px = nx + len * vx[k];
      ll py = ny + len * vy[k];
      ll dist = llabs(x - px) + llabs(y - py);
      if(mindist > dist){
        mindist = dist;
        mink = k;
      }
    }

    cout << angle[mink];
    nx += len * vx[mink];
    ny += len * vy[mink];
  }
  cout << endl;
}


int main(){
  int N;
  cin >> N;
  vector<vector<ll>> v;
  bool odd = false;
  bool even = false;
  rep(i,N){
    ll x, y;
    cin >> x >> y;
    v.push_back({x,y});
    if((llabs(x) + llabs(y))%2 == 0) even = true;
    else odd = true;
  }

  if(even && odd){
    cout << -1 << endl;
  }else{
    vector<ll> w;
    if(even) w.push_back(1);
    ll p = 1;
    rep(i,32){
      w.push_back(p);
      p *= 2;
    }
    reverse(ALLOF(w));
    cout << w.size() << endl;
    rep(i,w.size()){
      if(i>0) cout << " ";
      cout << w[i];
    }
    cout << endl;
    
    rep(i,N){
      solve(w, v[i][0], v[i][1]);
    }
  }
  
  return 0;
}
