#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ;
  cin >> N ;
  
  // 1110で割った余りが10より小さい
  // 1111で割った余りが0
  // 1000で割った余りを111で割った余り0  3888 > 888 > 0
  
  if ( ( N % 1110) < 10 ){
    cout << "Yes" << endl;
  }
  else if ( N % 1111 == 0 ){
    cout << "Yes" << endl;
  }
  else if ( (N % 1000) % 111 == 0 ) {
    cout << "Yes" << endl;
  }
  else if ( (N % 1000) == 0 ) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
