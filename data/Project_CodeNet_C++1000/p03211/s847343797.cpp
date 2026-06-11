#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  vector<char> C(S.size());
  for (int i = 0; i < S.size(); i++) {
    C.at(i) = S.at(i);
  }
  
  vector<int> N(S.size());
  for (int i = 0 ; i < S.size(); i++) {
    N.at(i) = C.at(i) - '0';
  }
  
  vector<int> n(S.size() - 2);
  for (int i = 0 ; i < S.size() - 2; i++) {
    n.at(i) = N.at(i)*100 + N.at(i+1)*10 + N.at(i+2);
  }
  
  vector<int> X(S.size() - 2);
  for (int i = 0 ; i < S.size() - 2; i++) {
    if (n.at(i) >= 753){
      X.at(i) = n.at(i) - 753;
    }
    else {
      X.at(i) = 753 - n.at(i);
    }
  }
  
  sort(X.begin(), X.end());
  cout << X.at(0) << endl;
}
  

