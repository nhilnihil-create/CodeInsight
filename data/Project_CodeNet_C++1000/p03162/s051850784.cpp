#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl1;
typedef vector<vl1> vl2;

int main()
{ ll i, j, k, n, kn, val, tmp, suma, maxa;

  cin>>n;
  vl2 veka(n+1, vl1(4)), dp(n+1, vl1(4));
  for(i=1;i<=n;i++) cin>>veka[i][1]>>veka[i][2]>>veka[i][3];

  veka[0][1]=0; veka[0][2]=0; veka[0][3]=0;
  dp[0][1]=0; dp[0][2]=0; dp[0][3]=0;

  for(i=1;i<=n;i++)
    { for(k=1;k<=3;k++)
       { suma=0;
         for(j=1;j<=3;j++)
           { if(j != k)
               { val=dp[i-1][j];
                 if(val>suma) suma = val;
               }
           }
         dp[i][k]+=(suma+veka[i][k]);
       }
    }

   suma=0;
   for(j=1;j<=3;j++)
     { val=dp[n][j];
       if(val>suma) suma = val;
     }
   cout << suma << endl;
  return 0;
}
/*
3
10 40 70
20 50 80
30 60 90
*/
