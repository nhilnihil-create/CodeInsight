#include <bits/stdc++.h>
using namespace std;


int main() {
  int A, B;
  cin >> A >> B;
  
  int cnt = 0, roll;
  for (int i=A/10000; i<=B/10000; i++) {
    for (int j=0; j<10; j++) {
      for (int k=0; k<10; k++) {
    	roll = i*10001 + j*1010 + k*100;
        if (A<=roll && roll<=B) cnt++;
      }
    }
  }
  
  cout << cnt << endl;

  return 0;
}
