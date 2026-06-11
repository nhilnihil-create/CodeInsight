#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t L0, L1, L2, Ln;
  L0 = 2;
  L1 = 1;
  L2 = 0;
  Ln = 1;
  for(int i = 0; i < N - 1; i++){
    Ln = L1 + L0;
    L2 = L0;
    L0 = L1;
    L1 = L0 + L2;
  }
  cout << Ln << endl;
}