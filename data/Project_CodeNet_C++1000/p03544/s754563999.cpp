#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  scanf("%d", &N);
  vector<int64_t> L(N + 1);
  
  L.at(0) = 2;
  L.at(1) = 1;
  
  for (int i = 2; i < N + 1; i++){
    L.at(i) = L.at(i-1) + L.at(i-2);
  }

  cout << L.at(N) << endl;
}
