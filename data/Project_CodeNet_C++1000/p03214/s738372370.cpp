#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int n;
  cin >> n;
  vector<double> a(n);
  double av = 0.0;
  rep(i,n) cin >> a[i], av += a[i];
  av /= (double)n;
  double dif = 1000.0;
  rep(i,n) {
    dif = min(dif, abs(av - a[i]));
  }
  rep(i,n) {
    if (dif == abs(av - a[i])) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
} 