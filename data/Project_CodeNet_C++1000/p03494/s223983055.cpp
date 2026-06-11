#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  
  //bool zero = true;
  int leastTry = 0;
  

    for (int i = 0; i < N; i++) {
      int num;
      cin >> num;
      int count = 0;
      while (num % 2 == 0) {
        num /= 2;
        count++;
      }
      if (count > 0) {
        if (i == 1) {
          leastTry = count;
        } else if (count < leastTry) {
          leastTry = count;
        }
      } else {
        leastTry = 0;
        break;
      }
    }
    cout << leastTry << endl;
        
        
  
}
