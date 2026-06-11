#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  
  vector<int> x, y;
  x.push_back(X);
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    x.push_back(a);
  }
  sort(x.begin(), x.end());
  y.push_back(Y);
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    y.push_back(a);
  }
  sort(y.begin(), y.end());
  
  if (x.back() < y.front()) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
  
  return 0;
}