#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;
  
  int x = -1, y = -1, z = -1;
  
  for (int i = 0; i <= N; i++){
    for (int j = 0; j <= N - i; j++){
      if (1000 * (N - i - j) == Y - 10000 * i - 5000 * j){
        x = i;
        y = j;
        z = N - i - j;
        break;
      }
    }
    if (x > -1){
      break;
    }
  }
  
  cout << x << " " << y << " " << z << endl;
}

