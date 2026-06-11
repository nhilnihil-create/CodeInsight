#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  for (int i =0; i < N ; i++){
    cin >> m.at(i);
    X -= m.at(i);
  }
  
  sort(m.begin(),m.end());
  int ans = m.size() + X/m.at(0);
  
  cout << ans << endl;
}
