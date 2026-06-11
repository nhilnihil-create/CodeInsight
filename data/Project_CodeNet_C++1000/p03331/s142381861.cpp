#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int digitsum(int n){
  int s = 0;
  while (n){
    s += n % 10;
    n /= 10;
  }
  return s;
}

int main() {
  int N;
  cin >> N;
  int min_s = 1000000;
  for (int i = 1; i < N/2 + 1; i++){
    int a = digitsum(i) + digitsum(N - i);
    min_s = min(min_s, a);
  }
  cout << min_s << endl;
}