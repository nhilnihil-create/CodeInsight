#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, ans = (1LL << 62);
  cin >> N >> K;
  vector<int64_t> X(N), Y(N);
  for (int i = 0; i < N; i++)
  {
    cin >> X[i] >> Y[i];
  }
  for (int i = 0; i < N; i++) // left
  {
    for (int j = 0; j < N; j++) // right
    {
      if (X[i] >= X[j])
        continue;
      for (int k = 0; k < N; k++) // top
      {
        for (int l = 0; l < N; l++) // bottom
        {
          if (Y[k] <= Y[l])
            continue;
          int64_t cnt = 0;
          for (int m = 0; m < N; m++)
          {
            if (X[i] <= X[m] && X[m] <= X[j] && Y[l] <= Y[m] && Y[m] <= Y[k])
              cnt++;
          }
          if (cnt >= K)
            ans = min(ans, (X[j] - X[i]) * (Y[k] - Y[l]));
        }
      }
    }
  }
  cout << ans << endl;
}