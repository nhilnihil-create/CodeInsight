#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum;
  cin >> N;
  sum = 0;
  for(int i = 1; i <= N; i*=10) {
    sum += N / i - N / (i * 10) * 10;
  }
  if(N % sum == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}