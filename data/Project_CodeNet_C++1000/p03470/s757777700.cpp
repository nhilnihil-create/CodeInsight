#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    cin >> d[i];
  }
    int species = 0;
  sort(d.begin(), d.end());
  for (int i = 0; i < N - 1; i++){
    if (d[i] != d[i+1]) {
      species++;
    }
  }
  cout << species + 1 << endl;
}