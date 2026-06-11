#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, H, maxa = 0, ans = 0;
  cin >> N >> H;
  vector<int64_t> A(N), B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i) >> B.at(i);
    maxa = max(maxa, A.at(i));
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  for (int i = 0; i < N; i++)
  {
    if (H <= 0)
      break;
    if (B.at(i) <= maxa)
      break;
    H -= B.at(i);
    ans++;
  }
  if (H > 0)
    ans += (H + maxa - 1) / maxa;
  cout << ans << endl;
}
