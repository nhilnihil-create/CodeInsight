#include <bits/stdc++.h>
using namespace std;

int main() { 
  int A, B;
  cin >> A >> B;
  int d = 0;
  for (int i = A; i <= B; i++) {
    if(i/10000==i%10 && i/1000%10==i%100/10){
      d++;

    }
  }
  cout << d << endl;
}