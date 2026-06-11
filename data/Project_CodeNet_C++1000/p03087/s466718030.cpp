#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, Q;
  cin >> N >> Q;
  vector<char> S(N);
  vector<int> memo(N);
  cin >> S.at(0);
  memo.at(0) = 0;
  for (int i = 1; i < N; i++) {
    cin >> S.at(i);
    if (S.at(i) == 'C' && S.at(i - 1) == 'A') {
      memo.at(i)++;
    }
    memo.at(i) += memo.at(i - 1);
  }
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << memo.at(r - 1) - memo.at(l - 1) << endl;
  }
}