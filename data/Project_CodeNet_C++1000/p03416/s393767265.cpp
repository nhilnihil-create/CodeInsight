#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >>B;
  int count = 0;
  int N = B-A+1;
  int M = A;
  
  for (int i = 0; i < N;i++){
    int a,b,c,d,e;
    a = M%10;
    M /=10;
    b = M%10;
    M /=10;
    c = M%10;
    M /=10;
    d = M%10;
    M /=10;
    e = M;
    if (a == e && b == d){
      count++;
    }
    A++;
    M = A;
  }
  
  cout << count << endl;
}

