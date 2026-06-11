#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int i_max, j_max;
  int total, count = 0;
  int judge = 0;
  
  cin >> N;
  
  i_max = N / 4 + 1;
  j_max = N / 7 + 1;
  
  for (int i = 0; i <= i_max; i++) {
    for (int j = 0; j <= j_max; j++) {
      total = 4*i + 7*j;
      if (total == N) {
		judge = 1;
        break;
      } else {
        continue;
      }
    }
  }
  
  if (judge == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }    
    
}
