#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int>vec(N);
  for (int i=0; i < N; i++){
  cin >> vec.at(i);
  }
  
  int a = 0;
  int A = 0;
  int B = 0;

  for (int i=0; i < N; i++){
    for (int j=i+1; j < N; j++){
      if (vec.at(i) > vec.at(j)){
      a = vec.at(i);
        vec.at(i) = vec.at(j);
          vec.at(j) = a;
      }
    }
  }
    
    int b;
    b = N / 2;
  if (2*b == N){
    for (int i=0; i < b; i++){
    B = B + vec.at (2 * i);
    }
  }else{
    for (int i=0; i < b;i++){
    B = B + vec.at (2 * i + 1);
    }
  }
    
    
    for (int i=0; i < N; i++){
    A = A + vec.at (i);
    }
  cout << A - 2*B << endl;
  
}
 