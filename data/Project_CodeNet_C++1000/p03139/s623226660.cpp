#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(A, B) << ' ' << max(A + B - N, 0) << endl;
  return 0;
}