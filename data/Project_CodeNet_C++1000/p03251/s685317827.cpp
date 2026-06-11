#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N);
  for (int i = 0; i < N; i++) cin >> x.at(i);
  vector<int> y(M);
  for (int i = 0; i < M; i++) cin >> y.at(i);

  int mx = *max_element(x.begin(), x.end());
  int mi = *min_element(y.begin(), y.end());
  
  for (int z = X + 1; z <= Y; z++) {
    if (z <= mx) continue;
    if (z > mi) continue;
    return cout << "No War" << "\n", 0;
  }
  cout << "War" << "\n";
}