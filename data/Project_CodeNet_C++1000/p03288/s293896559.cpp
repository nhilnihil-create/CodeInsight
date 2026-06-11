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
  int r;
  cin >> r;
  string ans;
  if(r<1200) ans = "ABC";
  else if(r<2800) ans = "ARC";
  else ans = "AGC";
  cout << ans << endl;
}
