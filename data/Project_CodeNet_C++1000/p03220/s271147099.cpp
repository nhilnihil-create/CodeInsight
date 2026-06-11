#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  int t, a;
  cin >> t >> a;

  vector<int> v(n);
  rep(i,n) cin >> v[i];

  double dt;
  int idx = 0;
  double min = INT_MAX;
  rep(i,n){
    dt = abs(a - (t - (v[i] * 0.006)));
    if (min > dt){
      min = dt;
      idx = i;
    }
  }

  cout << idx + 1 << endl;
  return 0;
}