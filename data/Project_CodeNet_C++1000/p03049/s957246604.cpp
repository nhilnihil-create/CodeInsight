#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int N;
  cin >> N;
  int countAB = 0;
  int count_A = 0;
  int countB_ = 0;
  int countB_A = 0;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    int M = s.size();
    if (s.at(0) == 'B' && s.at(M-1) == 'A'){
      countB_A++;
    }
    else if (s.at(M-1) == 'A'){
      count_A++;
    }
    else if (s.at(0) == 'B'){
      countB_++;
    }
    for (int j = 0; j < M-1; j++) {
      if (s.at(j) == 'A' && s.at(j+1) == 'B'){
        countAB++;
      }
    }
  }
  
  if (count_A == 0 && countB_ == 0){
    cout << countAB + max(countB_A-1,0) << endl;
  }
  else {
    cout << countAB + countB_A + min(countB_,count_A) << endl;
  }
}
    
    
  