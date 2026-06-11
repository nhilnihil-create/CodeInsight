#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  
  int answer = 0;
  
   for (int i = 0; i < N; i++) {
     
     if (i % 2 == 0) {
       answer += C.at(i);
     }
     else if (i % 2 == 1) {
       answer -= C.at(i);
     }
     
   }
  
  cout << answer << endl;
}