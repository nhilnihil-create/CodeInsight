#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
  int sum=0;
  while (n>0) {
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N, min=1000000; cin >> N;
  for (int i=1; i<N; i++) {
    if (min > sum(i)+sum(N-i)) min = sum(i)+sum(N-i);
  }
  cout << min << endl;
}