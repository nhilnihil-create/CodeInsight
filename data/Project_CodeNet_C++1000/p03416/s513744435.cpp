#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int n = 0;
  
 
  
  for ( int X = A; X < B + 1; X++ ) {
    int first, second, fourth, fifth;
    int x = X;
    
    first = x % 10;
    x = x / 10;
    second = x % 10;
    x = x / 100;
    fourth = x % 10;
    x = x / 10;
    fifth = x % 10;
    
    if ( first == fifth && second == fourth ) {
      n++;
    }
  }
  cout << n << endl;
}