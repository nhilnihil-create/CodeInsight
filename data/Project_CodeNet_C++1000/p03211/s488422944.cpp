#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string S;
  cin >> S;
  int ans = 100000;
  for (int i = 0; i < S.length() - 2; i++)
  {
    int num = 0;
    num += (S[i] - '0') * 100;
    num += (S[i + 1] - '0') * 10;
    num += (S[i + 2] - '0');
    ans = min(ans, abs(num - 753));
  }
  cout << ans << endl;
}
