#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define PI 3.1415926535

int main(void)
{
   string n;
   cin >> n;

   int max_val = 0;
   rep(i, n.size()) max_val += (n.at(i) - '0');

   int ans = n.at(0) - '1'; //一引いた数
   for (int i = 1; i < n.size(); i++)
      ans += 9;
   ans = max(ans, max_val);

   cout << ans << endl;

   return 0;
}
