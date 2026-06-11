#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> divs;
  for (int64_t i = 1; i * i <= M; i++)
  {
    if (M % i != 0)
      continue;
    divs.push_back(i);
    if (M / i != i)
      divs.push_back(M / i);
  }
  sort(divs.begin(), divs.end());
  reverse(divs.begin(), divs.end());
  for (auto d : divs)
  {
    if (M / d >= N)
    {
      cout << d << endl;
      return 0;
    }
  }
}