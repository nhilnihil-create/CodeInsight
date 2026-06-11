#include <bits/stdc++.h>

using namespace std;

long long A[200001], S[200001];

long long sum(int l, int r)
{
  return S[r] - S[l - 1];
}

int main()
{
  int N;
  scanf("%d", &N);
  
  A[0] = S[0] = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%lld", A + i);
    S[i] = A[i] + S[i - 1];
  }
  
  long long ans = 1e18;
  int lpt = 1, rpt = 3;
  for (int i = 2; i <= N - 2; i++) {
    while (lpt != i - 1 && abs(sum(1, lpt + 1) - sum(lpt + 2, i)) < abs(sum(1, lpt) - sum(lpt + 1, i))) lpt++;
    if (rpt == i) rpt++;
    while (rpt != N - 1 && abs(sum(i + 1, rpt + 1) - sum(rpt + 2, N)) < abs(sum(i + 1, rpt) - sum(rpt + 1, N))) rpt++;
    long long t[4] = {sum(1, lpt), sum(lpt + 1, i), sum(i + 1, rpt), sum(rpt + 1, N)};
    ans = min(ans, *max_element(t, t + 4) - *min_element(t, t + 4));
  }
  
  printf("%lld\n", ans);
  
  return 0;
}
