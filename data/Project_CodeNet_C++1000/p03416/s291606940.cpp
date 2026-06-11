#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  int B;
  cin >> A >> B;
  int N = B - A + 1;
  int n = 0;
  for (int i=0; i < N; i++){
    int K = A + i;
    int a;
    int b;
    int c;
    int d;
    a = K / 10000;
    b = (K / 1000) - 10*a;
    c = (K / 10) - (K / 100) * 10;
    d = K - ( K/10 ) * 10;
  if (a == d && b == c){
  n = n + 1;
  }
  }
  cout << n << endl;
}
    