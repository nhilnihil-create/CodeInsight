#include <bits/stdc++.h>
using namespace std;

int FindSum (int n) {
  int sum =0;
  while (n>0) {
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main () {
  int N; cin >> N;
  
  int ans =0, min = 100000;
  for (int i=1; i<N; i++) {
    ans = FindSum(i) + FindSum(N-i);
    if (ans < min) min = ans;
  }
  cout << min << endl;
}