#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int N, A, B; cin >> N >> A >> B;

  printf("%d %d\n", min(A, B), max(0, A+B-N));
}