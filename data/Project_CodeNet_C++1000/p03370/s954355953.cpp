#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, m[101];
  cin >> n >> x;
  
  int s = 0;
  int M = 712489;
  
  for(int i = 0; i < n; i++) {
    cin >> m[i];
    s += m[i];
    if(m[i] < M) M = m[i];
  }
  
  cout << n + (x - s) / M << endl;
}  