#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  vector<int> x(N);
  for (int i = 0; i < N; i++) cin >> x.at(i);
  sort(x.begin(), x.end());
  int E = x.at(N - 1);

  vector<int> y(M);
  for (int i = 0; i < M; i++) cin >> y.at(i);
  sort(y.begin(), y.end());
  int W = y.at(0);

  bool flag = false;
  for (int i = X + 1; i <= Y; i++) {
    if (E < i && W >= i) flag = true;
  }

  if (flag)
    cout << "No War" << endl;
  else
    cout << "War" << endl;
}