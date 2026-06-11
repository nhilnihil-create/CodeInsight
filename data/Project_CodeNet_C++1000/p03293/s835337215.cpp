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
  string s,t;
  cin >> s >> t;
  int n = s.size();
  s += s;
  rep(i,n){
    bool ok = [&]{
      rep(j,n) if(s[i+j]!=t[j]) return false;
      return true;
    }();
    if(ok){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
