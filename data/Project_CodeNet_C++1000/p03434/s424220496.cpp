#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int N;
  cin >> N;
  
  int A = 0;
  int B = 0;
  
  
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    
    cin >> a.at(i);
    
  }
  
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  
  for (int i = 0; i < N; i++) {
    
    if(i % 2 == 0) {
      
      A = A + a.at(0);
      
      a.at(0) = 0;
      sort(a.begin(), a.end());
      reverse(a.begin(), a.end());
      
    }else if (i % 2 == 1) {
      
      B = B + a.at(0);
      
      a.at(0) = 0;
      
      sort(a.begin(), a.end());
      reverse(a.begin(), a.end());
    }
    
  }
  cout << A - B << endl;
  
}