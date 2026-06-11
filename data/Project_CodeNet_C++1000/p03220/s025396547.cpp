#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  double t,a; cin >> t >> a;
  vector<double> h(n); rep(i,n) cin >> h[i];

  double temp = INF;
  int ans;
  rep(i,n){
    double tmp = t-h[i]*0.006;
    double test = abs(a-tmp);
    if(temp>=test){
      temp = test;
      ans = i+1;
    }
  }

  cout << ans << endl;
  
  return 0;
}
