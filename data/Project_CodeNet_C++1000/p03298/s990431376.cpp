#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
#define i64 int64_t
void agc26c()
{
  int N;
  string S;
  cin >> N >> S;
  string a, b;
  for (int i = 0; i < 2 * N; i++)
  {
    if (i < N)
      a += S[i];
    else
      b += S[i];
  }
  reverse(b.begin(), b.end());
  unordered_map<string, i64> ha, hb;
  for (int i = 0; i < (1 << N); i++)
  {
    string x = "", y = "";
    for (int j = 0; j < N; j++)
    {
      if (i & (1 << j))
        x += a[j];
      else
        y += a[j];
    }

    string temp = x + "," + y;
    auto itr = ha.find(temp);
    if (itr != ha.end())
    {
      itr->second++;
    }
    else
    {
      ha[temp] = 1;
    }
  }
  for (int i = 0; i < (1 << N); i++)
  {
    string x = "", y = "";
    for (int j = 0; j < N; j++)
    {
      if (i & (1 << j))
        x += b[j];
      else
        y += b[j];
    }

    string temp = x + "," + y;
    auto itr = hb.find(temp);
    if (itr != hb.end())
    {
      itr->second++;
    }
    else
      hb[temp] = 1;
  }
  i64 sum = 0;
  for (auto it = ha.begin(); it != ha.end(); it++)
  {
    bool flag = false;
    auto itr_2 = hb.find(it->first);
    if (itr_2 == hb.end())
      continue;
    if (it->first.substr(0, N / 2) == it->first.substr(N / 2 + 1, N / 2))
    {
      flag = true;
    }
    if (flag == true)
    {
      sum += it->second * itr_2->second;
    }
    else
    {
      sum += it->second * itr_2->second;
    }
  }
  cout << sum;
  return;
}
int main(void)
{
  agc26c();
  return 0;
}
