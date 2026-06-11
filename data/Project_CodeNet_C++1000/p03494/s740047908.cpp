#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int num = INT_MAX;
  for (int i=0; i<N; i++) {
    int A;
    cin >> A;
    int j=0;
    while (A % 2 == 0){
      A /= 2;
      j++;
    }
    if (num > j) {
      num = j;
    }
  }
  cout << num << endl;
}