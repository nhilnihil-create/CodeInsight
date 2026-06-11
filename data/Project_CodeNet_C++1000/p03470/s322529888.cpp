#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, step = 1;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    cin >> d.at(i);
  }
  sort(d.begin(), d.end());
  for (int j = 1; j < N; j++) {
    if (d.at(j - 1) < d.at(j)) {
      step++;
    }
  }
  cout << step << endl;
}