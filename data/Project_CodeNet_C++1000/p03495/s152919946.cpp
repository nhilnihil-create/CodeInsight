#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;
const int mod = 1000000007;

int main()
{
  int k, n;
  cin >> n >> k;
  //vector<int> A(n);
  vector<int> cnt(200001);
  int max = 0;
  rep(i, n)
  {
    int a;
    cin >> a;
    if (a > max)
    {
      max = a;
    }
    cnt.at(a)++;
  }
  all(cnt);
  reverse(cnt.begin(), cnt.end());
  int ans = 0;
  for (int i = k; i <= max; i++)
  {
    ans += cnt.at(i);
  }
  cout << ans << endl;
}
