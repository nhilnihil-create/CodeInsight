#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B;
  cin >> A >> B;
  int sum;
  sum = 0;
  while(A <= B){
    int a, b, c, d, e;
    a = A / 10000, e = A % 10;
    b = (A - a * 10000) / 1000, c = (A - a * 10000 - b * 1000) / 100;
    d = c = (A - a * 10000 - b * 1000 - c * 100) / 10;
    if (a == e && b == d) sum += 1;
    A++;
  
  }
  cout << sum << endl;
}