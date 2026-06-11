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
  int n; string s;
  cin >> n >> s;

  vector<int> r(n),l(n);
  rep(i,n-1){
    r[i+1] = r[i];
    if(s[i]=='W') r[i+1]++;
    l[n-1-i-1] = l[n-i-1];
    if(s[n-1-i]=='E') l[n-1-i-1]++;
  }
  int ans = n;
  rep(i,n) ans = min(ans,l[i]+r[i]);
  cout << ans << endl;
}
