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
   string a, b;
   cin >> a >> b;
   sort(all(a));
   sort(All(b));
   cout << (a < b ? "Yes" : "No") << '\n';
   return 0;
}