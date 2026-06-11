#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
   string s; cin >> s;
   int ans = 1000000000;
   string n = "753";
   int nn = (n[0] - '0') * 100 + (n[1] - '0') * 10 + (n[2] - '0');
   for(int i = 0; i < s.size() - 2; i++) {
      string m;
      for(int j = 0; j < 3; j++) {
         m.push_back(s[i+j]);
      }

      int mm = (m[0] - '0') * 100 + (m[1] - '0') * 10 + (m[2] - '0');
      ans = min(ans, abs(mm - nn));
   }

   cout << ans << endl;
}

int main()
{
   solve1();
}