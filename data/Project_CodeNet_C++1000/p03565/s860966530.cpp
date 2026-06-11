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
  int n = s.size(), m = t.size();
  rep(i,n-m+1){
    int ii = n-m-i;
    bool ok = true;
    rep(j,m){
      ok &= s[ii+j]=='?' || s[ii+j]==t[j];
    }
    if(ok){
      rep(j,m) s[ii+j] = t[j];
      rep(j,n) if(s[j]=='?') s[j] = 'a';
      cout << s << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
}
