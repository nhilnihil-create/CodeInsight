#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   int a, b, c;
   cin >> a >> b >> c;
   if (a == b)
   {
      cout << c << endl;
   }
   else if (b == c)
   {
      cout << a << endl;
   }
   else if (a == c)
   {
      cout << b << endl;
   }

   return 0;
}
