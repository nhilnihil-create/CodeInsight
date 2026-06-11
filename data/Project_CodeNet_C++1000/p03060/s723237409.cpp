#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> V(N), C(N);
  for (int i = 0; i < N; i++)
  {
    cin >> V[i];
  }
  for (int i = 0; i < N; i++)
  {
    cin >> C[i];
  }
  
  int ans = 0;
  for (int bit = 0; bit < (1 << N); bit++)
  {
    int X = 0, Y = 0;
    for (int i = 0; i < N; i++)
    {
      if (bit & (1 << i)) {
        X += V[i];
        Y += C[i];
      }
    }
    ans = max(ans, X - Y);
  }
  cout << ans << endl;
  return 0;
}
