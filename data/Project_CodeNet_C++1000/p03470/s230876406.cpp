#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> diameter(N);
  for (int i = 0; i < N; i++) {
    cin >> diameter.at(i);
  }
  sort(diameter.begin(), diameter.end());
  int x = 0;
  for (int i = 0; i < N; i++) {
    if (i > 0 && diameter.at(i - 1) == diameter.at(i)) {
    continue;
    }
    x += 1;
  }
  cout << x << endl;
}
