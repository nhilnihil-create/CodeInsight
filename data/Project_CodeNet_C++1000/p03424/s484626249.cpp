#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N;
  
  cin >> N;
 
  string S;
  rep (i, N) {
      cin >> S;
      
      if (S == "Y") {
          cout << "Four" << endl;
          break;
      } else {
          if (i >= N - 1) {
              cout << "Three" << endl;
              break;
          }
      }
  }
}