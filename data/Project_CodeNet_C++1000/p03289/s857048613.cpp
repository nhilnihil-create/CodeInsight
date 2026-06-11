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
  bool ans = [&]{
    int c = 0, m = 0;
    rep(i,n){
      if(i==0 && s[i]!='A') return false;
      if(2<=i&&i<=n-2 && s[i]=='C') ++c;
      if('a'<=s[i]&&s[i]<='z') ++m;
    }
    return c==1 && m==n-2;
  }();
  cout << (ans?"AC":"WA") << endl;
}
