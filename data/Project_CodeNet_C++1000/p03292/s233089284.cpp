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
  vector<int> a(3);
  rep(i,3) cin >> a[i];
  sort(a.begin(),a.end());
  int ans = 1e9;
  do {
    ans = min(ans,abs(a[2]-a[1])+abs(a[1]-a[0]));
  } while (next_permutation(a.begin(),a.end()));
  cout << ans << endl;
}
