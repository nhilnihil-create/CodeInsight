#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,X;
  cin >> N >> M;
  X = (1900 * M + 100 * (N-M))*pow(2,M);
  cout << X;
}

  
    