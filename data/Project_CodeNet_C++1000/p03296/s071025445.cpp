#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans = 0;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    if (i && A.at(i - 1) == A.at(i))
    {
      A.at(i) = -1;
      ans++;
    }
  }
  cout << ans << endl;
}