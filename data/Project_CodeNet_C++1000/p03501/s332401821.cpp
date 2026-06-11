#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int x;
  
  int plan1 = N * A;
  
  if (plan1 < B) {
    x = plan1;
  }
  else {
    x = B;
  }
  
  cout << x << endl;
}
