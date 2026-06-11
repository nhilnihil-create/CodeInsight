#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const ll NMAX = 200005;
const ll INF = (ULLONG_MAX - 5);

ll n, x;
ll a[NMAX], S[NMAX];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   cin >> n >> x;
   for (int i = 1; i <= n; i++)
      cin >> a[i], S[i] = S[i - 1] + a[i];

   ll minim = INF;
   for (int k = 1; k <= n; k++)
   {
      ll aici = 0;
      ll coef = 5;
      for (ll st = n - k + 1; st >= 1; st -= k)
      {
         // [st, st + k - 1]
         int dr = st + k - 1;
         aici += (S[dr] - S[st - 1]) * coef;

         if (coef == 5)
         {
            if (st != n - k + 1)
               coef = 7;
         }
         else
            coef += 2;

         if (st <= k) // ca sa nu scada sub 0
            break;
      }

      // ce a ramas
      if (n % k)
      {
         int st = 1, dr = n % k;
         aici += (S[dr] - S[st - 1]) * coef;
      }

      minim = min(minim, aici + k * x);
   }
   cout << minim + n * x;

   return 0;
}
