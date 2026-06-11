#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B,max,min;
  cin >>N >> A>> B;
  if(A<B)max=A;
  else max=B;
  if(N>=A+B)min=0;
  else min=A+B-N;
  cout <<max <<" "<<min;
  
}