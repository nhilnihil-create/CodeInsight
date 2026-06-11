#include <bits/stdc++.h>
using namespace std;

int main() {
  int m=0, M;
  vector<int> V(5);
  int p, t, S=0;
  for (int i=0; i<5; i++) {
    cin >> V[i];
    S+=((V[i]-1)/10+1)*10;
    p=(200-V[i])%10;
    if (m<p) {
      M=i;
      m=p;
    }
  }
  cout << S-m << endl;
}

