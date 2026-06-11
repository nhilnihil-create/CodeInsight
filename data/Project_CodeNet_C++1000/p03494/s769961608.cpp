#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int y = 1000000000;
  for (int i=0; i < N; i++){
    int x = 0;
    int A;
    cin >> A;
    int a = A / 2;
    while (A == 2*a){
      A = a;
      a = a / 2;
      x++;  
    }
    if (y > x){
    y = x;
    }
  }
 cout << y << endl;
}