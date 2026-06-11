#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> t(n+1),x(n+1),y(n+1);
  rep(i,n) cin >> t[i+1] >> x[i+1] >> y[i+1];
  
  rep(i,n){
    int d = abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
    int dt = t[i+1]-t[i];
    if(d>dt || dt%2!=d%2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
