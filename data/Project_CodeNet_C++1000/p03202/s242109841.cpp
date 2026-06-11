#include <bits/stdc++.h>
using namespace std;

int check(int m, vector<int>& A) {
  map<int, int> S;
  for (int i = 1; i < A.size(); i++) {
    if (A[i-1] < A[i]) continue;
    if (m == 1) return 0;
    int a = A[i];
    S.erase(S.upper_bound(a), S.end());
    while (S[a] == m-1) {
      a--;
      if (a == 0) return 0;
    }
    S[a]++;
    S.erase(S.upper_bound(a), S.end());
  }
  return 1;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int& a : A) cin >> a;

  int l = 0, r = N;
  while (1 < r - l) {
    int m = (l + r) / 2;
    if (check(m, A)) r = m;
    else l = m;
  }
  cout << r << endl;
}