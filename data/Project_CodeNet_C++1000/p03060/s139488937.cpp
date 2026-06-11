#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int>V(N);
  vector<int>C(N);
  for (int i = 0; i < N; i++) {
    cin >> V.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  vector<int>A(N);
  for (int i = 0; i < N; i++) {
    A.at(i) = V.at(i) - C.at(i);
  }
  
  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) > 0){
      sum += A.at(i);
    }
  }
  cout << sum << endl;
}
 