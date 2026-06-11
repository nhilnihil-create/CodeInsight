#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, ans = 0;
  string S;
  cin >> N >> K >> S;
  vector<int64_t> Count(1, 0);
  S.at(0) == '0' ? Count[0]-- : Count[0]++; // 0なら-1, iなら+1
  for (int i = 1; i < N; i++)
  {
    if (S.at(i) != S.at(i - 1))
      Count.push_back(0);
    S.at(i) == '0' ? Count.at(Count.size() - 1)-- : Count.at(Count.size() - 1)++;
  }

  for (int i = 0; i < Count.size(); i++)
    ans = max(ans, abs(Count.at(i)));

  vector<int64_t> Sum(Count.size() + 1, 0);
  for (int i = 0; i < Count.size(); i++)
    Sum.at(i + 1) = Sum.at(i) + abs(Count.at(i));

  int64_t length = Count.size(), zero = 0;
  for (int64_t i = 0; i < length; i++)
  {
    if ((K % 2 == 1 && Count.at(i) > 0) || (K % 2 == 0 && Count.at(i) < 0))
      continue;
    int64_t sum = 0;
    int64_t r = min(length - 1, i + K) + 1;
    int64_t l = max(zero, i - K);
    sum += Sum.at(r) - Sum.at(l);
    ans = max(ans, sum);
  }
  cout << ans << endl;
}