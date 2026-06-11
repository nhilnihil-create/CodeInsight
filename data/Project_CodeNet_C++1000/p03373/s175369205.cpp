#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B, C, X, Y;
  long long Min=1000000000;
  cin >> A >> B >> C >> X >> Y;
  rep(i, max(X,Y)+1) if(Min>=C*2*i+A*max(0,X-i)+B*max(0,Y-i)) Min=C*2*i+A*max(0,X-i)+B*max(0,Y-i);
  cout << Min << endl;
}