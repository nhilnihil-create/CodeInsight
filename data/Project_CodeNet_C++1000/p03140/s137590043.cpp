#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int N; string A, B, C; cin >> N >> A >> B >> C;

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    set<char> a = {A[i], B[i], C[i]};
    ans += a.size()-1;
  }

  cout << ans << endl;
}