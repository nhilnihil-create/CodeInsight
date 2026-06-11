#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, T;
  cin >> n >> T ;
  const int INF = 10005;
  int mcost = INF;

  REP(i,n){
    int c, t;
    cin >> c >> t;
    if(t > T) continue;

    mcost = min(mcost, c);
  }

  if(mcost == INF){
    cout << "TLE" << endl;
    return 0;
  }

  cout << mcost << endl;
  return 0;
}