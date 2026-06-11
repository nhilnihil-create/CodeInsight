#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  
  int total = A*B;
  int road = A+B-1;
  int x = total-road;
  
  cout << x << endl;
}