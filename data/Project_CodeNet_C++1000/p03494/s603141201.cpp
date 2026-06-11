#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0;i<N;i++) {
      cin >> A.at(i);
  }
  
  int count=0;
  int ans =0;
  bool limit = false;
  
  while(limit == false) {
      
  for(int i=0;i<N;i++) {
      if(A.at(i) % 2 ==0) {
          count++;
          A.at(i) /= 2;
      }
      
  else {
      limit = true;
      break;
  }
  }
  ans++;
  }
  cout << ans-1 << endl;
}
