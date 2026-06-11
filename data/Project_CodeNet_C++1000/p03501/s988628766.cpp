#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int APrice = N*A;
  int BPrice = B;
  
  int min = APrice < BPrice ? APrice : BPrice;
  cout << min << endl;
}