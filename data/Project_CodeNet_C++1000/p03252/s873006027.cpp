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
  string ss,tt;
  cin >> ss >> tt;
  int n = ss.size();
  auto s = [&](int i){ return ss[i]-'a'; };
  auto t = [&](int i){ return tt[i]-'a'; };

  vector<int> vs[26],vt[26];
  rep(i,n) vs[s(i)].push_back(i);
  rep(i,n) vt[t(i)].push_back(i);

  rep(si,26){
    if(vs[si].empty()) continue;
    int ti = t(vs[si][0]);
    for(int i:vs[si]){
      if(t(i)!=ti){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  rep(ti,26){
    if(vt[ti].empty()) continue;
    int si = s(vt[ti][0]);
    for(int i:vt[ti]){
      if(s(i)!=si){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
