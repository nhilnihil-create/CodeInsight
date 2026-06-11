#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int even = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a % 2 == 0) even++;
  }
  
  cout << pow(3, n) - pow(2, even) << '\n';
}