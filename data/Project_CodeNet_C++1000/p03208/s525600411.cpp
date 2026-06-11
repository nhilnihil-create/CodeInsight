#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, k;
  cin >> n >> k;
  vector <int> h(n);
  REP(i,n) cin >> h[i];

  sort(ALL(h));

  //for(auto x: h) cout << x << endl;

  int INF = 1000000009;
  int mx = INF;
  REP(i,n-k+1){
    int t = 0;
    t = h[i + k - 1]- h[i];
    mx = min(mx, t);
  }

  cout << mx << endl;
  return 0;
}
