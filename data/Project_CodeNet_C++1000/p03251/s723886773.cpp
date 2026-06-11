#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int n,m,X,Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n);
  vector<int> y(m);
  rep(i,n) cin >> x[i];
  rep(i,m) cin >> y[i];
  sort(x.rbegin(),x.rend());
  sort(y.begin(),y.end());
  int a = max(X,x[0]);
  int b = min(Y,y[0]);
  if(a >= b) puts("War");
  else puts("No War");
  return 0;
}
