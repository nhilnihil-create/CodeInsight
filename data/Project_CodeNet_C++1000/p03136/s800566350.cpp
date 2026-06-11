#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> data(N);
  
  for (int i = 0; i < N; i++) {
    cin >> data.at(i);
  }
  
  double sum = 0;
  int Lmax = 0;
  for (int i = 0; i < N; i++) {
    sum += data.at(i);
    Lmax = max(data.at(i), Lmax);
  }

  if (Lmax < sum / 2 ) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}
