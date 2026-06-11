#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N;
  
  cin >> N;
 
  int count = -1;
  rep (i, N) {
    int A = 0;
    cin >> A;
    
    int c = 0;
    while (A % 2 == 0) {
      c++;
      A /= 2;
    }
    
    if (count == -1 || c < count) {
        count = c;
    }
  }
  
  cout << count << endl;
}