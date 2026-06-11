#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  // ここにプログラムを追記
  int A, cnt, min = 100000000;
  for(int i=0; i<N; i++) {
    cin >> A;
    cnt = 0;
    while(A > 0) {
      if(A%2==1) {
        break;
      }
      cnt++;
      A /= 2;
    }
    if(min > cnt && A%2==1) {
      min = cnt;
    }
  }
  cout << min << endl;
}