#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A, B, C, K;
  cin >> A >> B >> C >> K;
  
  if(K%2)cout << B-A <<endl;
  else cout << A-B << endl;
}
