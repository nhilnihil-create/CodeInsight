#include<bits/stdc++.h>
using namespace std;

long long S[202020];
long long A[202020];
int N;
int main()
{
  scanf("%d", &N);
  for(int i=1; i<=N; ++i)
  {
    scanf("%lld", A+i);
    S[i] = S[i-1] + A[i];
  }
  long long ans = 0x3f3f3f3f3f3f3f3fll;
  int atp = 1;
  int ctp = 3;
  for(int tp=2; tp<=N-1; ++tp)
  {
    // A: (0, atp]
    // B: (atp, tp]
    // C: (tp, ctp]
    // D: (ctp, N]
    while(true)
    {
      long long Asum = S[atp]-S[0];
      long long Bsum = S[tp]-S[atp];
      long long Asuf = S[1+atp]-S[0];
      long long Bsuf = S[tp]-S[1+atp];
      if(abs(Asum-Bsum)<=abs(Asuf-Bsuf)) break;
      ++atp;
    }
    while(true)
    {
      long long Csum = S[ctp]-S[tp];
      long long Dsum = S[N]-S[ctp];
      long long Csuf = S[1+ctp]-S[tp];
      long long Dsuf = S[N]-S[1+ctp];
      if(abs(Csum-Dsum)<=abs(Csuf-Dsuf)) break;
      ++ctp;
    }
      long long Asum = S[atp]-S[0];
      long long Bsum = S[tp]-S[atp];
      long long Csum = S[ctp]-S[tp];
      long long Dsum = S[N]-S[ctp];
      ans = min(ans, max({Asum, Bsum, Csum, Dsum}) - min({Asum, Bsum, Csum, Dsum}));
  }
  printf("%lld\n", ans);
  return 0;
}