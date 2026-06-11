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
  string s; ll k; int n;
  cin >> s >> k;
  --k;
  n = s.size();
  
  char ans;
  rep(i,n) {
    ans = s[i];
    if(s[i]!='1') break;
    if(--k<0) break;
  }
  cout << ans << endl;
}
