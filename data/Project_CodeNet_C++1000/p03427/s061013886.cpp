#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  int count = 0;
  long long M = N;
  long long P = 1;
 
  for (int i = 0; i < 16; i++) {
    if (N / 10 != 0){
      N /= 10;
      count++;
      P *= 10;
    }
    else if (N / 10 == 0){
      break;
    }
  }
  
  if ((M + 1) % P == 0){
    cout << count * 9 + N << endl;
  }
  else {
    cout << count * 9 + N - 1 << endl;
  }
}



