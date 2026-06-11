#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N, ans = 0;
  cin >> N;
  vector<int> a(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }

  while (1)
  {
    bool e = true;
    for (int i = 0; i < N; i++)
    {
      if (a[i] % 2 == 0)
      {
        a[i] /= 2;
        ans++;
        e = false;
        break;
      }
    }
    if (e)
    {
      break;
    }
  }
  cout << ans << endl;
}
