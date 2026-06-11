#include <bits/stdc++.h>
using namespace std;
 
int main() {
int A,B,C;
  cin >> A >> B >> C;
  
  if(A == B && B == C){
 cout << A * 10 + B * 2 << endl;
  }
  
  else{
    cout << max(max(A,B),C) * 9 + A + B + C << endl;
  }
}
