#include <bits/stdc++.h>
using namespace std;
int main() {
 int a,b,c,d;
  cin >> a >> b >> c >> d;
   int res = 0;
  for (int A = 0; A <= a; ++A) {
    for (int B = 0; B <= b; ++B) {
      for (int C = 0; C <= c; ++C) {
        int total = 500*A + 100*B + 50*C;
        if(total==d){
          res++;
        }
      }
    }
  }
  cout << res << endl;
  
}
