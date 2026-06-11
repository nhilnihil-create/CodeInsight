#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  int T;
  int N;
  cin >> A >> T >> N;
  if (A * T > N) {
    cout << N << endl;
  }
  else if (A * T == N) {
    cout << N << endl;
  }
  else {
    cout << A * T << endl;
  }
}
