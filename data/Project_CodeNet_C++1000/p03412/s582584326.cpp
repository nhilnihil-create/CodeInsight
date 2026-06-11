#include <bits/stdc++.h>
using namespace std;

const int NMAX = 200005;

int n;
int a[NMAX], b[NMAX], c[NMAX], d[NMAX];

int *caut(int x)
{
   return lower_bound(d + 1, d + n + 1, x);
}

int main()
{
   cin >> n;
   for (int i = 1; i <= n; i++)
      cin >> a[i];
   for (int i = 1; i <= n; i++)
      cin >> b[i];

   int rez = 0;
   for (int bit = 0; bit <= 28; bit++)
   {
      for (int j = 1; j <= n; j++)
         c[j] = a[j] % (1 << (bit + 1)), d[j] = b[j] % (1 << (bit + 1));
      sort(d + 1, d + n + 1);
      int unu = 0;
      for (int j = 1; j <= n; j++)
         unu ^= caut ((1 << (bit + 1)) - c[j]) - caut((1 << bit) - c[j]) + caut((1 << (bit + 2)) - c[j]) - caut((3 << bit) - c[j]);
      rez ^= (unu & 1) << bit;
   }
   cout << rez;
   return 0;
}
