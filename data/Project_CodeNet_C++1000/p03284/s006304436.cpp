#include <bits/stdc++.h>

using namespace std;

int main() {
  double N, K;
  
  cin >> N >> K;
  
  cout << (ceil(N / K) - floor(N / K)) << endl;
  
  return 0;
}