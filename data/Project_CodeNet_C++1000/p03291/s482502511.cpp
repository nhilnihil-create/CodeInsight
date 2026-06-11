#include <bits/stdc++.h>
#include <vector>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP2(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define REPR(i, n) for (int i = (n)-1; i >= 0; --i)
#define REPx(x, a) for(auto x : a)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define SORTG(a) sort(ALL(a), greater<int>())
#define REVERSE(a) reverse(ALL(a))
#define bit_search(bit, n) REP(bit, 1<<(n))
#define bit_check(bit, i) (bit>>(i)) & 1
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL((a))), (a).end());} while(0)
#define ENDL cout << endl;
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VI = vector<int>;
using VVI = vector<VI>;
using Vll = vector<ll>;
using VVll = vector<Vll>;
using VC = vector<char>;
using VS = vector<string>;
using VB = vector<bool>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  ll N = S.size();
  VVll dp(N+1, Vll(4, 0));
  dp.at(0).at(0) = 1;
  REP(i, N)
  {
    if (S.at(i) == 'A' || S.at(i) == '?')
    {
      dp.at(i+1).at(0) += dp.at(i).at(0);
      dp.at(i+1).at(1) += dp.at(i).at(1);
      dp.at(i+1).at(2) += dp.at(i).at(2);
      dp.at(i+1).at(3) += dp.at(i).at(3);
      dp.at(i+1).at(1) += dp.at(i).at(0);
      dp.at(i+1).at(0) %= MOD;
      dp.at(i+1).at(1) %= MOD;
      dp.at(i+1).at(2) %= MOD;
      dp.at(i+1).at(3) %= MOD;
    }
    if (S.at(i) == 'B' || S.at(i) == '?')
    {
      dp.at(i+1).at(0) += dp.at(i).at(0);
      dp.at(i+1).at(1) += dp.at(i).at(1);
      dp.at(i+1).at(2) += dp.at(i).at(2);
      dp.at(i+1).at(3) += dp.at(i).at(3);
      dp.at(i+1).at(2) += dp.at(i).at(1);
      dp.at(i+1).at(0) %= MOD;
      dp.at(i+1).at(1) %= MOD;
      dp.at(i+1).at(2) %= MOD;
      dp.at(i+1).at(3) %= MOD;
    }
    if (S.at(i) == 'C' || S.at(i) == '?')
    {
      dp.at(i+1).at(0) += dp.at(i).at(0);
      dp.at(i+1).at(1) += dp.at(i).at(1);
      dp.at(i+1).at(2) += dp.at(i).at(2);
      dp.at(i+1).at(3) += dp.at(i).at(3);
      dp.at(i+1).at(3) += dp.at(i).at(2);
      dp.at(i+1).at(0) %= MOD;
      dp.at(i+1).at(1) %= MOD;
      dp.at(i+1).at(2) %= MOD;
      dp.at(i+1).at(3) %= MOD;
    }
  }
  cout << dp.at(N).at(3) << endl;

  return 0;
}