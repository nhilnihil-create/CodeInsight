#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  double ans = 0;
  rep(i,n){
    double x;
    string u;
    cin >> x >> u;
    if(u == "JPY") ans +=x;
    else ans += 380000 * x;
  }

  printf("%.6f\n",ans);
}
  
