#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
int main()
{
   char c[3][2];

   for (int i = 0; i < 2; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cin >> c[j][i];
         // cout << c[j][i];
      }
   }
   int cnt = 0;
   rep(i, 3)
   {
      rep(j, 1)
      {
         if (c[j][i] == c[2 - j][1 - i])
         {
            cnt++;
         }
      }
   }
   if (cnt == 3)
   {
      cout << "YES" << endl;
   }
   else
   {
      cout << "NO" << endl;
   }
   return 0;
}
