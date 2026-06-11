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
  string s;
  cin >> s;
  bool ans = true;
  set<string> v;
  rep(i,n-1){
    v.emplace(s);
    string t;
    cin >> t;
    if(t[0] != s[s.size()-1]) ans = false;
    if(v.count(t)>0) ans = false;
    swap(s,t);
  }
  cout << (ans?"Yes":"No") << endl;
}
