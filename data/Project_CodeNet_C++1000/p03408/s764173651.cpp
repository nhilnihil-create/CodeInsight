#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, k = 0, v = 0;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) cin >> s.at(i);
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) cin >> t.at(i);
  
  for (string a : s) {
    for (string b : s) if (a == b) k++;   
    for (string b : t) if (a == b) k--;   
    if (v < k) v = k;
    k = 0;
  }
    
  cout << v << endl;
  return 0;
}
