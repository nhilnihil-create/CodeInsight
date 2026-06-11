#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int m = 1001001001, M = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    m = min(a, m);
    M = max(a, M);
  }
  cout << M - m << endl;
}
    