#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t sum = 0;
  
  for (int i = 0; i < N; i++) {
    
    int a; cin >> a;
    
    a--; sum += a;
    
  }
  
  cout << sum << endl;
  
}