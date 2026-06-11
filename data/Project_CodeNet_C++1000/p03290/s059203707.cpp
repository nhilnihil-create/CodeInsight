#include "bits/stdc++.h"
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mFOR(i, a, b) for (int i = a; i > b; i--)
#define MP make_pair
#define PB push_back
#define ALL(v) v.begin(), v.end()
#define N 100007
#define INF 1000000007
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll fceil(ll a, ll b) { return (a % b == 0 ? a / b : a / b + 1); }
int main()
{
   ll d, g, sum_score = 0;
   int ans = INF, sum_qnum = 0, partial_ans = -1;
   cin >> d >> g;
   vector<ll> p(d, 0), c(d, 0);
   for (int i = 0; i < d; i++)
      cin >> p[i] >> c[i];

   for (int i = 0; i < (1 << d); i++)
   {
      sum_score = 0;
      sum_qnum = 0;
      partial_ans = -1;
      for (int j = d - 1; j >= 0; j--)
      {

         if ((i >> j) & 1)
         {
            sum_score += 100 * (j + 1) * p[j] + c[j];
            sum_qnum += p[j];
         }
         else if (partial_ans == -1)
         {
            partial_ans = j;
         }
      }
      if (partial_ans >= 0)
         for (int j = 0; j < p[partial_ans] - 1; j++)
         {
            if (sum_score >= g)
               break;
            sum_score += 100 * (partial_ans + 1);
            sum_qnum++;
         }
      if (sum_score >= g)
         ans = min(ans, sum_qnum);
   }
   cout << ans << endl;
   return 0;
}
