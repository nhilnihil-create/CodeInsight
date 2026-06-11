#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,Q;
  string S;
  cin >> N >> Q >> S;
  
  vector<int>l(Q);
  vector<int>r(Q);
  for (int i = 0; i < Q; i++) {
    cin >> l.at(i) >> r.at(i);
  }
   
  vector<int>A(N);
  A.at(0) = 0;
  for (int i = 1; i < N; i++) {
    if (S.at(i) == 'C' && S.at(i-1) == 'A'){
      A.at(i) = A.at(i-1) + 1;
    }
    else {
      A.at(i) = A.at(i-1);
    }
  }
  
  for (int i = 0; i < Q; i++) {
    cout << A.at(r.at(i)-1) - A.at(l.at(i)-1) << endl;
  }
}
  