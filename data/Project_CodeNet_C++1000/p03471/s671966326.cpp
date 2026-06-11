#include <bits/stdc++.h>
using namespace std;

bool loop(int &N,int &Y) {
  int tmp1, tmp2;
  for (int i = 0; i <= N; i++){
    tmp1 = Y - 10*i;
    for (int j = 0; j <= N-i; j++) {
      tmp2 = tmp1 - 5*j;
      if (tmp2 == N-i-j) {
        cout << i << " " << j << " " << tmp2 << endl;
        return false;
      }
    }
  }
  return true;
}

int main() {
  int N, Y;
  cin >> N >> Y;
  Y /= 1000;



  if (loop(N,Y)) {
    cout << "-1 -1 -1" << endl;
  }
}