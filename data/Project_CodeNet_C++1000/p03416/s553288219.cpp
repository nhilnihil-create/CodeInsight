#include <bits/stdc++.h>
using namespace std;

int main() {
 int A,B;
  cin >> A >> B;
  int C = 0;
  for (int i=A ; i <= B; i++){
    if ( i/10000 == i%10 ){
      if ( i%10000/1000 == i%100/10 ){
        C = C + 1;
      }
    }
  }
  cout << C << endl;
}
