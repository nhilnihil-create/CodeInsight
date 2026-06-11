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
  int n;
  cin >> n;

  int a = 4;
  int b = 7;

  int ans  = 0;
  bool ok = false;

  REP(i, 26){
    REP(j,16){
      ans = a*i + b*j;
      if(ans == n) ok = true;
      if(n > ans) continue;
    }
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
