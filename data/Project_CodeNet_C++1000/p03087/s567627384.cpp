#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  int L = S.length();
  vector<int> f(L, 0);

  /* 'AC'を発見したら1 */
  for (int i = 1; i < L; i++)
    if (S[i - 1] == 'A' && S[i] == 'C') f[i] = 1;
  /* i番目までに出てきた'AC'の累積和をf[i]に格納 */
  for (int i = 1; i < L; i++) f[i] += f[i - 1];

  /* l, q 入力部分 */
  vector<int> l(Q, 0), r(Q, 0);
  for (int i = 0; i < Q; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }

  /* f[右端]-f[左端] で[l, r]に含まれる'AC'の個数が得られる */
  for (int i = 0; i < Q; i++) cout << f[r[i]] - f[l[i]] << endl;
}