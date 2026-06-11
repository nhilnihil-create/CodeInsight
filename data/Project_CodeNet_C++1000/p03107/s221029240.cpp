#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//------------------------//
// 0と１が両方存在している -> どこかで0と１が隣り合っている点が存在する
// min (num0, num1)  が答え




int main(){
  string s;
  cin >> s;

  int cnt1 = 0, cnt0 = 0;

  REP(i,s.size()){
    if(s[i] == '0') ++cnt0;
    else{ ++cnt1;}
  }

  int ans = 2 * min(cnt0, cnt1);
  cout << ans << endl;


  return 0;
}
