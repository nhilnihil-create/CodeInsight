#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl1;

int main()
{ ll i, k, n, kn, val, tmp, suma, maxa;

  cin>>n>>kn;
  vl1 veka(n+1), dp(n+1);
  for(i=1;i<=n;i++) cin>>veka[i];

  dp[1]=0;

  for(i=2;i<=n;i++)
    { if(kn<i) maxa=kn; else maxa=i-1;
      suma=LLONG_MAX;
      for(k=1;k<=maxa;k++)
       { val=veka[i]-veka[i-k];
         if(val<0) val=-val;
         if(dp[i-k]+val<suma) suma = dp[i-k]+val;
       }
      dp[i]+=suma;
    }
  cout << dp[n] << endl;
  return 0;
}
/*
5 3
10 30 40 50 20
*/
