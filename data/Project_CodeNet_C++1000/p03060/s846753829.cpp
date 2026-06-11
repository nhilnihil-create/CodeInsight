#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V(N);
  vector<int> C(N);
  for (int i = 0; i < N; i++)
    cin >> V.at(i);
  for (int j = 0; j < N; j++)
    cin >> C.at(j);
  
  int count = 0;
  for (int k = 0; k < N; k++) {
    if (V.at(k) - C.at(k) > 0)
      count += V.at(k) - C.at(k);
  }
  cout << count << endl;
}