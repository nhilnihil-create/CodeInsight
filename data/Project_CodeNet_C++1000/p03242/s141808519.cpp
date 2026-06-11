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
  REP(i, s.size()){
    if(s[i] == '1') s[i] = '9';
    else if(s[i] == '9') s[i] = '1';
  }

  cout << s << endl;
  return 0;
}