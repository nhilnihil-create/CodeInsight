#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  if(N == 3) {
    vector<int> ans = {2, 5, 63};
    REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
    cout << "\n";
    return 0;
  }
  FOR(i, 2, N-1) {
    if(i%3 != 1 && (N-i)%2 == 0 && i <= 15000 && (N-i) <= 5000) {
      int even = i;
      int odd = N-i;
      vector<int> ans;
      REP(i, even) ans.push_back(2*i+2);
      REP(i, odd) ans.push_back(6*i+3);
      REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
      cout << "\n";
      return 0;
    }
  }

}