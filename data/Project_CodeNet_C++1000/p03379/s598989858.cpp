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
  vector<int> x(n),a(n);
  rep(i,n) cin >> x[i];
  rep(i,n) a[i] = x[i];
  sort(x.begin(),x.end());
  int l = n/2-1, r = n/2;
  rep(i,n){
    if(a[i]<=x[l]) cout << x[r] << endl;
    else cout << x[l] << endl;
  }
}
