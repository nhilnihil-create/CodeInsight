#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans=0;
  cin >> N;
  vector<int> value(N);
  vector<int> cost(N);

  for (int i = 0; i < N; i++) cin >> value.at(i);
  for (int j = 0; j < N; j++) cin >> cost.at(j);
  
  for (int k = 0; k < N; k++) if (cost.at(k) < value.at(k)) ans += value.at(k) - cost.at(k);

  cout << ans << endl;
}