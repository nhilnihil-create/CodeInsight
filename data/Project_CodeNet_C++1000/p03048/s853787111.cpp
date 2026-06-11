#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  rep(i, 3001)
  {
    rep(j, 3001)
    {
      int v = i * R + j * G;
      if (N >= v && (N - v) % B == 0)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}