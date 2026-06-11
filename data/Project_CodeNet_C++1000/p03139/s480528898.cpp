#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int max_n = min(A,B);
  int min_n;
  if(A + B <= N) min_n = 0;
  else min_n = A + B - N;
  cout << max_n << " " << min_n << endl;
}