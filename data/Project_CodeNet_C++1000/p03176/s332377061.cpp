#include <iostream>
#include <vector>
 
using namespace std;
 
int N;
vector<int> h;
vector<int> a;
vector<size_t> dp;
 
void update_max(int i, size_t val)
{ 
  for (; i < N; i = (i | (i+1)))
    dp[i] = max(dp[i], val);
}
 
size_t get_max(int r)
{ 
  size_t res = 0;
  for (; r >= 0; r = (r & (r+1)) - 1)
    res = max(res, dp[r]);
  return res;
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  cin >> N;
 
  h.resize(N);
  a.resize(N);
 
  dp = vector<size_t>(N+1, 0);
 
  for (int i = 0; i < N; ++i)
  { 
    cin >> h[i];
  }
  for (int i = 0; i < N; ++i)
  { 
    cin >> a[i];
  }
  size_t res = 0;
 
  for (int i = 0; i < N; ++i)
  {
    const size_t cur_max = get_max(h[i]-1) + a[i];
    update_max(h[i], cur_max);
    res = max(res, cur_max);
  }
  cout << res << endl;
 
  return 0;
}