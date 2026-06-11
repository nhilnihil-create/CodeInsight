#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(A, B) << " ";
  if (A + B - N > 0)  {
    cout << A + B - N << endl;
  }
  else {
    cout << 0 << endl;
  }
}