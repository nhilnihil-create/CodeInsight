#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  string s, t;
  cin >> s >> t;

  s += s;

  REP(i,t.size()){
    bool ok = true;
    REP(j,t.size()){
      if(s[i+j] != t[j]) ok = false;
    }
    if(ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
