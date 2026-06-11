#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  for (int i = 0; i < M; i++)
  {
    cin >> B[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    int temp = C;
    for (int j = 0; j < M; j++)
    {
      int A;
      cin >> A;
      temp += A * B[j];
    }
    if (temp > 0)
    {
      ans++;
    }
    
  }
  cout << ans << endl;
  return 0;
}
