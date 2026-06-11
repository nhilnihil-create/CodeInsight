#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  long long l0 = 2, l1 = 1;
  
  if(n==0) {cout << l0 << endl; return 0;}
  if(n==1) {cout << l1 << endl; return 0;}
  long long l2;
  for(int i = 2; i <= n; i++){
    l2 = l0 + l1;
    l0 = l1;
    l1 = l2;
  }
  cout << l2 << endl;
    
  return 0;
}