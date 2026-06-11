#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  int m = 0;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++){
    
    int x;
    cin >> x;
    vec.at(i) = x;
  }
  
  sort(vec.begin(), vec.end());
  
  for (int i = 0; i < N; i++){
    
    int y;
    y = i + 1;
    
    if (y < N){
      if (vec.at(i) < vec.at(y)){
        m = m + 1;
      }
    }
  }
  
  cout << m + 1 << endl;
  
  
}