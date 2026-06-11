#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int i = 0;
  while(1){
      i += N;
      if ((i % N ==0) && (i % 2 == 0)) {
          cout << i << endl;
          return 0;
      }
  }
}
