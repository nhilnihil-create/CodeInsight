#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, A, B, count=1, sum=0;
  cin >> N >> A;
  for (int i=0; i<N-1; i++) {
    cin >> B;
    if (B==A) { 
      ++count;
    }
    else {
      sum+=count/2;
      count=1;
    }
    A=B;
  }
  sum+=count/2;
  cout << sum;
  return 0;
}