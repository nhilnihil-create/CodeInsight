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
    if ((s[i] - '0') == now)
    {
      cnt++;
    }
    else
    {
      Nums.push_back(cnt);
      now ^= 1;
      cnt = 1;
    }
  }
  Nums.push_back(cnt);
  if (Nums.size() % 2 == 0)
  {
    Nums.push_back(0);
  }

  vector<int> sum(Nums.size() + 1);
  for (int i = 0; i < Nums.size(); i++)
  {
    sum[i + 1] = sum[i] + Nums[i];
  }

  int Add = 2 * k + 1;

  int ans = 0;
  for (int i = 0; i < Nums.size(); i += 2)
  {
    int left = i;
    int right = min(i + Add, (int)Nums.size());
    int tmp = sum[right] - sum[left];

    ans = max(tmp, ans);
  }

  cout << ans << endl;
}
