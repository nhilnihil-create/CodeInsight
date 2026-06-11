#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <time.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for (i = 0; i < n; i++)
#define P pair<int, int>

int main()
{
  string s;
  cin >> s;
  int sz = s.size();
  int a = 0, b = 0;
  for (int i = 0; i < sz; i++)
  {
    if (i % 2 == s[i] - '0')
    {
      a++;
    }
    else
    {
      b++;
    }
  }

  cout << min(a, b) << endl;
}
