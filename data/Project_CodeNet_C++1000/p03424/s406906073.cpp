#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  vector<char> s(N);
  for (int i=0; i<N; i++) {
    cin >> s.at(i);
  }
  
  int p, w, g, y=0;
  for (auto x : s) {
    if (x=='P') p=1;
    else if (x=='W') w=1;
    else if (x=='G') g=1;
    else if (x=='Y') y=1;
  }
  
  if(p+w+g+y==4) cout << "Four" << endl;
  else cout << "Three" << endl;

  return 0;
}
