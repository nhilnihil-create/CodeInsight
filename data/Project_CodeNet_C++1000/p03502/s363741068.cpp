#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int n = N, m = 0;
  while (N > 0){
    m+= N % 10;
    N/=10;
  }
  cout << (n % m == 0 ? "Yes" : "No") <<endl;
}