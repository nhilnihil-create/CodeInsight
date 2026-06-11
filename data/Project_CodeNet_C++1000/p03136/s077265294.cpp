#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int N;
  cin >> N;
  vector<int> l; l.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> l[i];
  }
  sort(l.begin(), l.end());
  int sm = 0;
  for (int i = 0; i < N - 1; ++i) {
    sm += l[i];
  }
  if (sm > l.back()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
