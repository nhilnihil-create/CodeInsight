#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B;cin>>A>>B;
  
  int sumA=2*A-1;
  int sumAB=A+B;
  int sumB=2*B-1;
  
  cout<<max(max(sumA,sumB),sumAB)<<endl;
}