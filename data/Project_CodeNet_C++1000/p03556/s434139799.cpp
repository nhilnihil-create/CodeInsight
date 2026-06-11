#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  while(true) {
    if (int(sqrt(N)) * int(sqrt(N)) == N) {
      cout << N << endl;
      return 0;
    }
    N--;
  }
}