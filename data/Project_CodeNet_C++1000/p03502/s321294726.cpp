#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  int f = N%10, tmp = N;
  for (int i=0; i<N; i++) {
    tmp /= 10;
    f += tmp%10;
  }
  
  if (N%f==0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
