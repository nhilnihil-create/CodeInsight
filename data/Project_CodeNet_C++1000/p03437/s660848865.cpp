#include <bits/stdc++.h>
using namespace std;
int main () {
  long A, B;
  cin >> A >> B;
  if(A % B == 0){
    cout << -1 << endl;
    return 0;
  }
  long count = 1;
  while(1){
    if((count * A) % B != 0){
      cout << count * A << endl;
      return 0;
    }
    count++;
  }
  return 0;
}
