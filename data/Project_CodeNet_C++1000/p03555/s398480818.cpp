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

  bool ok = true;

  if(s[0] != t[2]) ok = false;
  if(s[1] != t[1]) ok = false;
  if(s[2] != t[0]) ok = false;

  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
