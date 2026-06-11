#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> V(N);
  set<string> S;
  for (int i=0; i<N; i++) {
    cin >> V[i];
    S.insert(V[i]);
  }
  
  string ans="Yes";
  for (int i=0; i<N-1; i++) {
    if (V[i][V[i].size()-1]!=V[i+1][0]) {
      ans="No";
      break;
    }
  }
  if (S.size()!=V.size()) {
    ans="No";
  }
  cout << ans << endl;
}
