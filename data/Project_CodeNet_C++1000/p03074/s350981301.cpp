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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> Nums;
  int now = 1;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == (char)('0' + now))
    {
      cnt++;
    }
    else
    {
      now = 1 - now;
      Nums.push_back(cnt);
      cnt = 1;
    }
  }
  Nums.push_back(cnt);
  if (Nums.size() % 2 == 0)
  {
    Nums.push_back(0);
  }

  int ans = 0;
  int Add = 2 * k + 1;

  int left = 0;
  int right = 0;
  int tmp = 0; // [left, right)のsum
  for (int i = 0; i < Nums.size(); i += 2)
  {
    int Nextleft = i;
    int Nextright = min(i + Add, (int)Nums.size());

    while (Nextleft > left)
    {
      tmp -= Nums[left];
      left++;
    }

    while (Nextright > right)
    {
      tmp += Nums[right];
      right++;
    }

    ans = max(ans, tmp);
  }

  cout << ans << endl;
}
