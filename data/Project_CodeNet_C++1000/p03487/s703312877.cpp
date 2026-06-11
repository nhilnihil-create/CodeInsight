#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define All(a) a.rbegin(), a.rend()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(10), cout << fixed
int main()
{
   ios;
   int n;
   cin >> n;
   map<int, int> mp;
   for (int i = 0, a; i < n; ++i)
      cin >> a, mp[a]++;
   int ans = 0;
   for (auto i : mp)
   {
      if (i.ff != i.ss)
      {
         if (i.ss > i.ff)
            ans += abs(i.ff - i.ss);
         else
            ans += i.ss;
      }
   }
   cout << ans << '\n';
   return 0;
}