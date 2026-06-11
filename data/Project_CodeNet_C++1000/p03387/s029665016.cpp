#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  int M = max(max(A,B),max(B,C));//maximum of three integers
  int sum = A + B + C; //invariant of three integers
  
  while( (sum+M) %2 == 1){
    M ++;
  }
  
  int dif = 3*M - (A+B+C);
  int count = dif / 2;
  
  cout << count << endl;
}