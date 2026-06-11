#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, A, min = 10000000, kaunto = 0;
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> A;
    while (A % 2 == 0) {
      kaunto++;
      A = A / 2;
    }
    if (min > kaunto) {min = kaunto;}
    kaunto = 0;
  }
  cout << min << endl;
}