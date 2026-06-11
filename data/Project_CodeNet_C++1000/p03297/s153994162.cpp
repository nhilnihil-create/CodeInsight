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
lint gcd(lint a, lint b) {
  if(a < b) {
    swap(a, b);
  }
  while(b > 0) {
    lint r = a % b;
    a = b;
    b = r;
  }
  return a;
}
lint lcm(lint a, lint b) {
  return a * b / gcd(a, b);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  REP(t, T) {
    lint A, B, C, D;
    cin >> A >> B >> C >> D;
    if(A < B || D < B) {
      cout << "No" << "\n";
      continue;
    }
    if(C >= B-1) {
      cout << "Yes" << "\n";
      continue;
    }
    lint g = gcd(B, D);
    A = A % g;
    lint cnt = (B-1-A)/g;
    yes(A+cnt*g <= C);
  }
}