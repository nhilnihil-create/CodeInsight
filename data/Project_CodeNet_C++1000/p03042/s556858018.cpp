#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
/* clang-format on */

int main() {
  string s;
  cin >> s;
  int a = stoi(s.substr(0, 2)), b = stoi(s.substr(2, 2));
  if (1 <= a && a <= 12 && 1 <= b && b <= 12)
    cout << "AMBIGUOUS\n";
  else if (1 <= a && a <= 12)
    cout << "MMYY\n";
  else if (1 <= b && b <= 12)
    cout << "YYMM\n";
  else
    cout <<"NA\n";
  return 0;
}
