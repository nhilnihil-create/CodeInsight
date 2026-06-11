#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0 , A = 0 , M = 0;
  cin >> N >> A;
  
  M = N % 500;
  
  if (A >= M)
    cout << "Yes";
  else cout << "No";
}