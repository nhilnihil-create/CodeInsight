#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  int x[3];
  cin >> A >> B;
  x[0] = A + B;
  x[1] = A - B;
  x[2] = A * B;
  sort(begin(x), end(x));
  cout << x[2] << "\n";
  return 0;
}
