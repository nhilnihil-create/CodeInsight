#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;

int main()
{
  int a, b, t;
  cin >> a >> b >> t;
  int cnt = 0;
  for (int i = a; i < t + 0.5; i = i + a)
  {
    cnt += b;
  }
  cout << cnt << endl;
}
