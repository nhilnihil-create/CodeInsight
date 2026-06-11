#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int max_A, min_A;
  int A;
  cin >> A;
  max_A = min_A = A;

  for (int i=1;i<N;i++) {
    cin >> A;
    max_A = (max_A<A)? A : max_A;
    min_A = (min_A>A)? A : min_A;
  }

  cout << max_A - min_A << endl;
}
  
  