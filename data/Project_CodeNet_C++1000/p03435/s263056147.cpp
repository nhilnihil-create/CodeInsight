#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int c11,c12,c13,c21,c22,c23,c31,c32,c33;
  cin >> c11 >> c12 >> c13 >> c21 >> c22 >> c23 >> c31 >> c32 >> c33;
  for(int a1=0; a1<=100; a1++) {
    for(int a2=0; a2<=100; a2++) {
      for(int a3=0; a3<=100; a3++) {
        int b1 = c11 - a1;
        int b2 = c12 - a1;
        int b3 = c13 - a1;
        if(b1==c21-a2 && b1==c31-a3 && b2==c22-a2 && b2==c32-a3 && b3==c23-a2 && b3==c33-a3) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}