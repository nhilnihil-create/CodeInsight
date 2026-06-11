#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
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
  string s;
  cin >> s;
  int N = s.size();
  if(s[N-1] == '1' || s[0] == '0' || s[N-2] == '0') {
    cout << -1 << endl;
    return 0;
  }
  vector<bool> bo(N);
  REP(i, N) {
    if(i <= N-i-2) {
      if((s[i] == '1' && s[N-i-2] == '0') || (s[i] == '0' && s[N-i-2] == '1')) {
        cout << -1 << endl;
        return 0;
      } else if(s[i] == '1' && s[N-i-2] == '1') {
        bo[i] = true;
      }
    }
  }
  int last = 1;
  REP(i, N-1) {
    cout << last << " " << (i+2) << "\n";
    if(bo[i]) last = i+2;
  }
}