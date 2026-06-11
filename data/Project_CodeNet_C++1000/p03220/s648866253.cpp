#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  REP(i,n) cin >> h[i];

  const int INF = 100000;

  double temp;
  double mabs = INF;
  int pos;

  REP(i,n){
    temp = t - h[i] * 0.006;
    if(abs(a-temp) < mabs){
      pos = i;
      mabs = abs(a-temp);
    }
  }

  ++pos;

  cout << pos << endl;
  return 0;
}