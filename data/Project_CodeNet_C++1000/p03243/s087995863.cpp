#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, n, cont;
  cin >> N;
  while (true) {
    cont=0;
    n=N;
    while (n>=10) {
      if (n%10==n%100/10) {
        n/=10;
        continue;
      }
      cont=1;
      break;
    }
    if (cont==0) {break;}
    N++;
  }
  cout << N << endl;
}
