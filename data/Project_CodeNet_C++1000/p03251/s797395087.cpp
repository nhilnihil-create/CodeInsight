#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  int xmax = -100;
  rep(i,n){
    int X;
    cin >> X;
    xmax = max(X,xmax);
  }
  int ymin = 100;
  rep(i,m){
    int Y;
    cin >> Y;
    ymin = min(Y,ymin);
  }
  string ans;
  if(x + 1 <= y && xmax + 1 <= ymin && max(x,xmax) < min(y,ymin)) ans = "No War";
  else ans = "War";
  cout << ans << endl;
}