#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, i = 1000;
  cin >> N;
  for (int j = 0; j < N; j++){
    int A, k = 0, l = 2;
    cin >> A;
    while (A % l == 0){
      l *=2;
      k++;
    }
    if (k < i)
      i = k;
  }
  cout << i << endl;
}