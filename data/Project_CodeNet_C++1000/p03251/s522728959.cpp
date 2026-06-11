#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;;
  vector<int>x(n);
  vector<int>y(m);
  rep(i,n) cin >> x[i];
  rep(i,m) cin >> y[i];
  sort(x.rbegin(), x.rend());
  sort(y.begin(), y.end());
  int x_max = x[0];
  int y_min = y[0];
  bool OK = false;
  for (int i = X+1; i <= (Y); ++i){
    if(x[0] < i && i <= y[0]) {
      OK =true;
      break;
    }
  }
  if(OK) puts("No War");
  else puts("War");
  
  return 0;
}
