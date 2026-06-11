#include<bits/stdc++.h>
using namespace std;

int kakuinowa (int n) {
  int sum=0;
  while (n>0) {
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main() 
{
  int N; cin >>N;
  int min = 100000;
  int Sum;
  
  for (int i=1; i<N; i++) {
    Sum = kakuinowa(i) + kakuinowa(N-i);
    if (Sum<min) min = Sum;
    
  }
  cout << min << endl;
}