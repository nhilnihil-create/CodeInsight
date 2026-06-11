#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   int a, b;
   cin >> a >> b;
   if ((a + b) % 2 == 0)
   {
      cout << (a + b) / 2 << endl;
   }
   else
   {
      cout << (a + b) / 2 + 1 << endl;
   }
   return 0;
}
