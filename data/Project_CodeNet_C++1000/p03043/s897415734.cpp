#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  
  vector<int>count(N);
  for (int i = 0; i < N; i++) {
    count.at(i) = (K+i)/(i+1) -1; 
  }
  
  vector<int>A(N,0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 18; j++) {
      if (count.at(i) != 0){
        A.at(i)++;
        count.at(i) /= 2;
      }
    }
  }
    
  vector<int>B(18);
  B.at(0) = 1;
  for (int i = 1; i < 18; i++) {
    B.at(i) = B.at(i-1) * 2;
  }
  
  double sum = 0;
  for (int i = 0; i < N; i++) {
    sum += 1.0/B.at(A.at(i));
  }
  
  printf("%.10lf\n", sum/N);
}
    
  
  

