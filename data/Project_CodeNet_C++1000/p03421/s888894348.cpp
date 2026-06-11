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
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> lenlist;
  lenlist.push_back(A);
  if(B > 1) {
    lint x = (N-A) / (B-1);
    lint d = (N-A) % (B-1);
    if(x <= 0 || x > A || (x == A && d != 0)) {
      cout << -1 << endl;
      return 0;
    }
    REP(i, B-1) lenlist.push_back(i<d ? x+1 : x);
  } else if(N != A) {
    cout << -1 << endl;
    return 0;
  }
  
  vector<int> ans;
  REP(i, B) {
    REP(j, lenlist[i]) {
      ans.push_back(N-lenlist[i]+1+j);
    }
    N -= lenlist[i];
  }
  REP(i, ans.size()) cout << ans[i] << (i!=N-1 ? " " : "");
  cout << "\n";
  

}