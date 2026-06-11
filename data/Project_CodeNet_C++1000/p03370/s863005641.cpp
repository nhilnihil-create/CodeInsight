#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,X; cin >> N >> X;
  vector<int> m(N);
  int ans=0;
 
  for(int i=0; i<N; i++) cin >> m.at(i);
  sort(m.begin(),m.end());
  
  for(int i=0; i<N; i++) {
    if(X >= m.at(i)) {
      X -= m.at(i);
      ans +=1;
    }
  }
  while(X >= m.at(0)) {
    X -= m.at(0);
    ans +=1;
  }
  cout << ans << endl;
}