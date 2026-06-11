#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){
  int N;
  cin >> N;
  int ans = 1000000;

  for (int A = 1; A <= N-1; A++){
    int B = N-A;

    int sumA = 0, sumB = 0;
    int x = A, y = B;
    for (int k = 0; k < 6; k++){
      sumA += x % 10;
      sumB += y % 10;
      x /= 10;
      y /= 10;
    }
    if(ans > sumA+sumB) ans = sumA + sumB;
  }

  cout << ans << endl;
  return 0;
}
