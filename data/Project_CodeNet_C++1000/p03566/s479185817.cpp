#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<cstring>
using namespace std;
long long int mod = 1e9 + 7;
template <class T>
void inputV(vector<T> &x, int n){
  for(int i=0; i<n; i++) cin >> x[i];
}

int main() {
  int n; cin >> n;
  vector<int> t(n+1, 0);
  vector<int> v(n);
  for(int i=1; i<=n; i++){
    cin >> t[i];
    t[i] += t[i-1];
  }
  for(int i=0; i<n; i++) cin >> v[i];
  vector<double> mv(40010, 0.0);
  for(int i=1; i<=n; i++){
    for(int j=t[i-1]*2+1; j<=t[i]*2; j++){
      mv[j] = min(mv[j-1]+0.5, v[i-1]*1.0);
    }
  }

  mv[t[n]*2] = 0.0;
  for(int i=n; i>=1; i--){
    for(int j=t[i]*2; j>=t[i-1]*2+1; j--){
      mv[j-1] = min({mv[j]+0.5, mv[j-1], v[i-1]*1.0});
    }
  }
  double ans = 0.0;
  for(int i=0; i<=t[n]*2; i++){
    ans += (mv[i]+mv[i+1])/4;
  }
  printf("%.4lf\n", ans);

  return 0;
}
