#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  
  int sum, answer;
  
  for ( int i = 0; i < A + 1 ; i++){
    for (int j = 0; j < B + 1 ; j++){
      for (int k = 0; k < C + 1 ; k++){
        sum = 500 * i + 100 * j + 50 * k;
//        cout << sum << endl;
        if ( sum == X){
          answer ++ ;
        }
      }
    }
  }
  cout << answer << endl;
}