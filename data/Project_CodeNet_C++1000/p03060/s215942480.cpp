#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans=0;
  cin >> N;
  vector<int> value_item(N);
  vector<int> cost_item(N);

  for (int i = 0; i < N; i++) cin >> value_item.at(i);
  for (int j = 0; j < N; j++) cin >> cost_item.at(j);
  
  for (int k = 0; k < N; k++) if (cost_item.at(k) < value_item.at(k)) ans = ans + value_item.at(k) - cost_item.at(k);

  cout << ans << endl;
}