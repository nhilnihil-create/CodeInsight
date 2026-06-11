#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
   char a, b;
   cin >> a >> b;

   if (a == b)
   {
      cout << "=" << endl;
   }
   else if (a < b)
   {
      cout << "<" << endl;
   }
   else
   {
      cout << ">" << endl;
   }
   return 0;
}
