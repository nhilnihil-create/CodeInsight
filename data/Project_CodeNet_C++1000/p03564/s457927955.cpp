#include <bits/stdc++.h>
using namespace std;
int64_t N, K;

int64_t dfs(int n, int i)
{
  if (i == N)
    return n;
  i++;
  return min(dfs(n * 2, i), dfs(n + K, i));
}

int main()
{
  cin >> N >> K;
  cout << dfs(1, 0) << endl;
}