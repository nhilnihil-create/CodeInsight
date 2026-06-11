#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N = 0;
  cin >> N;
 
  long old_L = 2LL;
  long old_A = 1LL;
  long new_A = 1LL;
  
  for (int i = 1; i < N; i++) {
    new_A = old_L + old_A;
    old_L = old_A;
    old_A = new_A;
  }
  
  cout << new_A << endl;
}