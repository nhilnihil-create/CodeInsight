#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int N = S.size();
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'o'){
      count++;
    }
  }

  if (15-N + count >= 8){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
      
  
    