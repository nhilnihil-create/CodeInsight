#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int sum = 0, max_p = 0;
  for ( int i = 0; i < N; i++ ) {
    int p;
    cin >> p;
    sum += p;
    max_p = max(max_p, p);
  }

  cout << sum - max_p + max_p/2 << endl;  
  
  return 0;
}
