#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s,t;
  cin >> s >> t;
  
  vector<int>A(s.size());
  for (int i = 0; i < s.size(); i++) {
    A.at(i) = s.at(i) - '0';
  }
  sort(A.begin(), A.end());
    
  vector<int>B(t.size());
  for (int i = 0; i < t.size(); i++) {
    B.at(i) = t.at(i) - '0';
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  
  for (int i = 0; i < min(t.size(),s.size()); i++) {
    if (A.at(i) < B.at(i)){
      cout << "Yes" << endl;
      return 0;
    }
    else if (A.at(i) > B.at(i)){
      cout << "No" << endl;
      return 0;
    }
  }
  
  if (s.size() < t.size()){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}

  