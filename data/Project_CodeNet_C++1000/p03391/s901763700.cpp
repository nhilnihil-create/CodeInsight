#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL 9223372036854775
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define MOD 1000000007
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

#define int long long

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a)  begin((a)), end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

const int MAX_N = 200005;
int N;
int A[MAX_N], B[MAX_N];

signed main()
{
  cin >> N;
  int cnt = 0;
  int sumA = 0;
  int minA = INF_INT_MAX;
  int minB = INF_INT_MAX;
  bool flag = true;

  REP(i,N) {
    cin >> A[i] >> B[i];
    if(A[i] > B[i]) {
      if(minB == INF_INT_MAX) {
        minB = B[i];
      } else if(minB > B[i]) {
        minB = B[i];
      }
    }
    if(A[i] != B[i]) {
      flag = false;
    }
  }

  if(flag) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  flag = true;
  REP(i,N) {
    if(B[i] == minB && flag) {
      ans += A[i] - B[i];
      flag = false;
    } else {
      ans += A[i];
    }
  }

  cout << ans << endl;

  return 0;
}