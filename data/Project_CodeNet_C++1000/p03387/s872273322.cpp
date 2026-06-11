#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  ll A,B,C; cin>>A>>B>>C;
  int ans =0;

  if (A%2 == B%2 && A%2 == C%2) {
    int max_num = max(max(A, B),C);
    while (A < max_num) {
      A += 2;
      ans ++;
    }
    while (B < max_num) {
      B += 2;
      ans ++;
    }
    while (C < max_num) {
      C += 2;
      ans ++;
    }
    cout << ans << endl;
    return 0;
  }

  int even = 0;
  int odd = 0;
  if (A%2==0) even++;
  else odd++;
  if (B%2==0) even++;
  else odd++;
  if (C%2==0) even++;
  else odd++;

  // 偶奇を揃える
  if (even > odd) {
    if (A%2==0) A++;
    if (B%2==0) B++;
    if (C%2==0) C++;
  } else {
    if (A%2!=0) A++;
    if (B%2!=0) B++;
    if (C%2!=0) C++;
  }
  ans ++;

  int max_num = max(max(A, B),C);
  while (A < max_num) {
    A += 2;
    ans ++;
  }
  while (B < max_num) {
    B += 2;
    ans ++;
  }
  while (C < max_num) {
    C += 2;
    ans ++;
  }
  cout << ans << endl;
  return 0;
}