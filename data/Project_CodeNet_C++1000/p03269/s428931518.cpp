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
  int L;
  cin >> L;
  int N = 1;
  int tmp = 1;
  while(tmp <= L) {
    N++;
    tmp *= 2;
  }
  N--;
  tmp /= 2;
  L -= tmp;
  int now = tmp;
  tmp /= 2;
  vector<int> u;
  vector<int> v;
  vector<int> c;
  REP(i, N-1) {
    u.push_back(i+1);
    v.push_back(i+2);
    c.push_back(0);
    u.push_back(i+1);
    v.push_back(i+2);
    c.push_back(tmp);
    if(L >= tmp) {
      u.push_back(1);
      v.push_back(i+2);
      c.push_back(now);
      now += tmp;
      L -= tmp;
    }
    tmp /= 2;
  }
  cout << N << " " << u.size() << "\n";
  REP(i, u.size()) cout << u[i] << " " << v[i] << " " << c[i] << "\n";
}