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
  --n;
  vector<int> c(n),s(n),f(n);
  rep(i,n) cin >> c[i] >> s[i] >> f[i];

  rep(i,n){
    int t = 0;
    for(int x=i;x<n;++x){
      t = max(t,s[x]);
      t = s[x] + (t-s[x]+f[x]-1)/f[x]*f[x] + c[x];
    }
    cout << t << endl;
  }
  cout << 0 << endl;
}
