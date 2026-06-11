#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 29);

int main()
{
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> A(M);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    A.at(i) = make_pair(b, a);
  }
  sort(A.begin(), A.end());
  int ans = 0;
  int last = -INF;
  for (int i = 0; i < M; i++)
  {
    if (last <= A.at(i).second)
    {
      ans++;
      last = A.at(i).first;
    }
  }
  cout << ans << endl;
}