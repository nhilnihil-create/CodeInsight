#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  double n,m,d;
  cin >> n >> m >> d;
  double ans = (m-1)*2*(n-d)/(n*n);
  if(d == 0) ans = (m-1)/n;
  cout << fixed;
  cout << setprecision(9) << ans << endl;
}