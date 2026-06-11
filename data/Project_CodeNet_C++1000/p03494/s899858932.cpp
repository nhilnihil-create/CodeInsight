#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, num, min = 32;
  cin >> N;
  
  for (int i = 0; i < N; i++){
    cin >> A;
    num = 0;
    while (A % 2 == 0){
      A = A / 2;
      num += 1;
    }
    if (min < num)
      continue;
    else
      min = num;
  }
  cout << min << endl;
}
