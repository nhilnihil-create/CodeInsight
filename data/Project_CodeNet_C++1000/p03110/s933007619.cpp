#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<double> x(n);
  vector<string> u(n);
  rep(i,n) cin >> x[i] >> u[i];

  double BTC_yen = 380000.;

  double ans = 0.;
  rep(i,n){
    if(u[i] == "BTC") ans+=x[i]*BTC_yen;
    else ans+=x[i];
  }

  printf("%.5f\n",ans);
  
  return 0;
}
