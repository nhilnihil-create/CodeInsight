#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  
  map<string, int> U;
  
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string si;
    cin >> si;
    U[si] += 1;
  }
  cin >> M;
  for (int i = 0; i < M; ++i) {
    string si;
    cin >> si;
    U[si] -= 1;
  }

  vector<int> V;
  V.push_back(0);
  for (const auto& x : U) {
    V.push_back(x.second); 
  }
  sort(V.begin(), V.end(), greater<int>());
  cout << V.at(0) << endl;
}