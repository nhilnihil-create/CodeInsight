#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  if (N == 1) { cout << vec[0] << endl; return 0; }
  
  int tmp = __gcd(vec[0], vec[1]);
  
  for (int i = 2; i < N; i++) tmp = __gcd(tmp, vec[i]);
  
  cout << tmp << endl;
  
}
