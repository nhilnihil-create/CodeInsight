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
  string s;
  cin >> s;
  int n = s.size();
  s = "0"+s+"0";
  vector<int> v;
  rep(i,n+1) if(s[i]!=s[i+1]) v.push_back(i);
  int ans = n;
  rep(i,v.size()) ans = min(ans,max(v[i],n-v[i]));
  cout << ans << endl;
}