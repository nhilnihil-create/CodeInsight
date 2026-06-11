#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t sum = 0;
  
  vector<int64_t> vec(5, 0);
  
  string title = "MARCH";
  
  for (int i = 0; i < N; i++) {
    
    string S; cin >> S; char head = S.at(0);
    
    for (int j = 0; j < title.size(); j++) {
      if (head == title.at(j)) vec.at(j)++;
    }
    
  }
  
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 5; k++) {
        sum += vec[i] * vec[j] * vec[k];
      }
    }
  }
  
  cout << sum << endl;
  
}