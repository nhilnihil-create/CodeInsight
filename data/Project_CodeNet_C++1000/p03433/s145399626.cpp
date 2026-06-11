#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A;
  cin >> N >> A;
  
  bool ans = false;
  
  for (int i; i <= A; i++) {
  if ((N - i) % 500 == 0) 
    ans = true;
  }
  
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}