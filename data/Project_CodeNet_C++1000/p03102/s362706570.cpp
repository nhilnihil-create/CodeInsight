#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n, m, c;
  cin >> n >> m >> c;

  vector<int> b(m);
  vector<int> a(m);

  int sum = 0;
  int flag = 0;

  rep(i, m) cin >> b.at(i);

  for (int i = 0; i < n;i++){
    sum = 0;
    rep(j, m)
    {
      cin >> a.at(j);
      sum += a.at(j) * b.at(j);
    }
    // cout << sum << endl;
    if (sum + c > 0)
      flag++;
  }

  cout << flag;
}
