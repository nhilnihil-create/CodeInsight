#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int i = 0;
  
  for (i = 0; i < N; i++) {
    cin  >> vec.at(i);
  }
  
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int count = 0;
  int count_2 = 0;
  
  for (i = 0; i < N; i += 2) {
    count += vec.at(i);
  }
  
  for (i = 1; i < N; i += 2) {
    count_2 += vec.at(i);
  }
  
  cout << count - count_2 << endl;
  
}
    
    
    
    
    
    
    
    
    
    
    
    
    
      
    
  