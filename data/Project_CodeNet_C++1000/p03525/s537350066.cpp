#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>

int count[13];

int main()
{
  int n;
  scanf("%d", &n);
  count[0] = 2;
  count[12] = 1;
  for (int i = 0; i < n; ++i)
  {
    int a;
    scanf("%d", &a);
    count[a]++;
  }
  std::vector<int> time;
  std::vector<int> amb;
  for (int i = 0; i <= 12; ++i)
  {
    if (count[i] >= 3)
    {
      puts("0");
      return 0;
    }
    else if (count[i] == 2)
    {
      count[i] = 0;
      if (i == 0 || i == 12) time.emplace_back(i);
      else
      {
        time.emplace_back(i);
        time.emplace_back(24 - i);
      }
    }
    else if (count[i] == 1)
    {
      if (i == 12) continue;
      amb.emplace_back(i);
    }
  }
  
  int ans = 0;
  int sz = time.size();
  int lim = 1 << amb.size();
  for (int i = 0; i < lim; ++i)
  {
    for (int j = 0; j < amb.size(); ++j)
    {
      time.emplace_back(i & (1 << j) ? 24 - amb[j] : amb[j]);
    }
    int min = 24;
    for (int a = 0; a < time.size() - 1; ++a)
    {
      for (int b = a + 1; b < time.size(); ++b)
      {
        int dif = std::abs(time[b] - time[a]);
        min = std::min(min, std::min(dif, 24 - dif));
      }
    }
    if (min > ans) ans = min;
    time.erase(std::next(time.begin(), sz), time.end());
  }
  printf("%d\n", ans);
  return 0;
}