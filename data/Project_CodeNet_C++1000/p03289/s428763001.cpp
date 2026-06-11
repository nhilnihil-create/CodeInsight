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
  string s;
  cin >> s;

  bool ok = true;

  if(s[0] != 'A') ok = false;
  else s[0] += 32;

  int cnt = 0;
  for(int i = 2; i < s.size() -1 ; i++){
    if(s[i] == 'C') {
    ++cnt;
    s[i] += 32;
    }

  }
  if(cnt != 1) ok = false;

  REP(i, s.size()){
    if(isupper(s[i])) ok = false;
  }

  if(ok) cout << "AC" << endl;
  else cout << "WA" << endl;


  return 0;
}
