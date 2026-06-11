#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, T, A;
  cin >> N >> T >> A;
  vector<int> height(N);
  vector<double> diff(N);
  int index = 0;
  double minimum = 100000000;
  
  for (int i = 0; i < N; i++) {
    cin >> height.at(i);
    diff.at(i) = abs(T - height.at(i) * 0.006 - A);
    if (diff.at(i) <= minimum){
      minimum = diff.at(i);
      index = i + 1;
    }
  }
  
  cout << index << endl;
  return 0;
}
