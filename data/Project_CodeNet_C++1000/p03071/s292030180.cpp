#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, max;
  int x[3];
  cin >> A >> B;
  x[0] = A + A - 1;
  x[1] = A + B;
  x[2] = B + B - 1;
  max = x[0];
  if(x[0] < x[1])
    max = x[1];
  if(x[1] < x[2])
    max = x[2];
  cout << max << "\n";
  return 0;
}
