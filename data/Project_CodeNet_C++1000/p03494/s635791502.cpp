#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int rmax = 200;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    
    int imax = 0;
	while (a) {
      if ((a % 2) == 0) {
        a /= 2;
        imax ++;
      } else {
        break;
      }
    }
    
    if (imax < rmax) {
      rmax = imax;
    }
  }
  
  cout << rmax << endl;
}
