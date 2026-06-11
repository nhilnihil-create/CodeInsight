#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,m,X,Y;
  cin >>n >>m >>X >>Y;
  int maxx = X;
  int miny = Y;
  rep(i,n) {
    int x;
    cin >>x;
    maxx = max(maxx, x);
  }
  rep(i,m) {
    int y;
    cin >>y;
    miny = min(miny, y);
  }
  if(maxx>=miny) cout << "War" << endl;
  else cout << "No War" << endl;
  return 0;
}