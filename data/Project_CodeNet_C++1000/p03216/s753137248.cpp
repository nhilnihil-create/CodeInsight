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
  lint N;
  cin >> N;
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  REP(q, Q) {
    lint k;
    cin >> k;
    lint l = 0;
    lint cnt = 0;
    lint dcnt = 0;
    lint mcnt = 0;
    lint ans = 0;
    REP(r, N) {
      if(r-l == k) {
        if(S[l] == 'D') {
          cnt -= mcnt;
          dcnt--;
        } else if(S[l] == 'M') {
          mcnt--;
        }
        l++;
      }
      if(S[r] == 'M') {
        cnt += dcnt;
        mcnt++;
      } else if(S[r] == 'C') {
        ans += cnt;
      } else if(S[r] == 'D') {
        dcnt++;
      }
    }
    cout << ans << "\n";
  }
}