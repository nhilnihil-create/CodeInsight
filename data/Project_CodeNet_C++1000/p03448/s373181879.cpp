#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,X;
  int count = 0, keep = 0;
  int i,j,k,price = 0;
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> X;
    // 500 coin 0 ~ A
    for (i = 0; i <= A; i++){     
      // 100 coin 0 ~ B
      for (j = 0; j <= B; j++){
        // 50  coin 0 ~ C
        for (k = 0; k <= C; k++){
          price = 500 * i + 100 * j + 50 * k;
          if(price == X) count++;
        }
      }
    }
  cout << count << endl;
}