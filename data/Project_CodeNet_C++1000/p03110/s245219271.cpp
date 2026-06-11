#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int main() {
  int n;
  cin>>n;
  double x;string u;
  double ans = 0;
  rep(i,n){
    cin>>x>>u;
    if(u == "JPY") ans += x;
    if(u == "BTC") ans += x * 380000.0;
  }
  cout<<setprecision(10)<<ans<<endl;
  return 0;
}