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

  int ans = 0;
  REP(i, s.size()){
    if(s[i]== '+') ++ans;
    else --ans;
  }

  cout << ans << endl;
  return 0;
}
