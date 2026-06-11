#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans=0;
  cin >> N;
  vector<int> item(N);
  
  for (int i = 0; i < N; i++) cin >> item.at(i);
  
  sort(item.begin(), item.end());
  for (int j = 0; j < N-1; j++) ans = ans + item.at(j);
  ans = ans + item.at(N-1) / 2;
  cout << ans << endl;
}