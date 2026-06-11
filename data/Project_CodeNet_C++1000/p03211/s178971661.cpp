#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  string s;
  cin >> s;
  int n = s.size();
  int ans = 1000;
  int x = 0;
  REP(i, n-2){
    x = (s[i] - '0') * 100 + (s[i+1]- '0') * 10 + (s[i+2]-'0');
    ans = min(abs(753-x), ans);
    //cout << x << endl;
  }

  cout << ans << endl;
  return 0;
}