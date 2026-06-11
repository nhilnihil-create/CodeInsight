#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, K;
  cin >> N >> K;
  int ans = 0;
  if (N < K)
    ans = 1;
  else if (N % K != 0)
    ans = 1;
  cout << ans << endl;
  return 0;
}