#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N, l[100001] = {}, r[100001] = {};
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> l[i] >> r[i];
  }
  ++N;
  sort(l, l + N);
  sort(r, r + N);
  int64 ret = 0, cost = 0;
  for(int i = 0; i < N; i++) {
    cost += l[N - i - 1] - r[i];
    ret = max(ret, cost * 2);
  }
  cout << ret << endl;
}