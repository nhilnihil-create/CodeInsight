#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i, N) for (int i = 0; i < N; i++)
#define REP1(i, N) for (int i = 1; i < N; i++)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ANS(a) cout << a << endl
#define SORT(V) sort(V.begin(), V.end())
#define RSORT(V) sort(V.rbegin(), V.rend())
#define DBG(V) for (auto v : V) cout << v << " "; cout << endl

unsigned long A, B, C;

int
main()
{
  cin >> A >> B >> C;

  
  int ans;
  if (A > B && A > C) {
    ans = B * C / 2;
  } else if (B > A && B > C) {
    ans = A * C / 2;
  } else {
    ans = A * B / 2;
  }
  ANS(ans);
}

