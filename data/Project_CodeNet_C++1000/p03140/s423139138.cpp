#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  string A;
  cin >> A;
  
  string B;
  cin >> B;
  
  string C;
  cin >> C;
  
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) == B.at(i) && B.at(i) == C.at(i)) {
    } else if (A.at(i) != B.at(i) && B.at(i) != C.at(i) && C.at(i) != A.at(i)){
      count = count + 2;
    } else {
      count++;
    }
  }
 
  cout << count << endl;
}