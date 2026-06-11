#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  string s;
  string t;
  cin >> s;
  REP(i,s.size()){
    if(i == 4 || i == 7) continue;
    t += s[i];
  }
  if(t > "20190430") cout << "TBD" << endl;
  else cout << "Heisei" << endl;
  return 0;
}