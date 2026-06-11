#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, ans = 0;
  cin >> A >> B >> C >> X;
  for (int i = 0; i <= A; i++){
    for (int j = 0; j <= B; j++){
      for (int k = 0; k <= C; k++){
        if (500 * i + 100 * j + 50 * k == X){
          if(i != 0 || j != 0 || k != 0){
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}