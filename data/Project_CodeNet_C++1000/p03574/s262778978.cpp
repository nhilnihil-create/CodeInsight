#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int r, c; cin >> r >> c;
   char a[r+2][c+2];
   for(int i = 0; i < r+2; i++)
      for(int j = 0; j < c+2;j++)
         a[i][j] = 'x';

   for(int i = 1; i <= r; i++)
   {
      for(int j = 1; j <= c; j++)
         cin >> a[i][j];
   }

   for(int i = 1; i <= r; i++)
   {
      for(int j = 1; j <= c; j++)
      {
         int cnt = 0;
         if(a[i][j] == '.')
         {
            for(int k = i -1; k <= i+1; k++)
            {
               for(int h = j-1; h <= j+1; h++)
               {
                  if(a[k][h] == '#')
                     cnt++;
               }
            }
            a[i][j] = (char)cnt;
         }

      }
   }
   for(int i = 1; i <= r; i++)
   {
      for(int j = 1; j <= c; j++)
      {
         if(a[i][j] != '#')
            cout << (int)a[i][j];
         else
            cout << a[i][j];
      }
      cout << nl;
   }

   return 0;
}
