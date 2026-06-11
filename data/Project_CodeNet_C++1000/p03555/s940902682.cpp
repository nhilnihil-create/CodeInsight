#include <bits/stdc++.h>
using namespace std;

int main () {
  /*
  vector<vector<string>> data(2, vector<string>(3));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> data.at(i).at(j);
    }
  }
  */
  /*
  vector<string> A(1);
  cin >> A;
  vector<string> B(1);
  cin >> B;

  string answerb = "";
  answerb = reverse(B.begin(), B.end());
  if (A == answerb) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << end;
  }
  */
  string A, B;
  cin >> A >> B;

  //cout << A.size() << B.size() << endl;
  if (A.at(0) == B.at(2)) {
    if (A.at(1) == B.at(1)) {
      if (A.at(2) == B.at(0)) {
        cout << "YES" << endl;
      }
      else {
        cout << "NO" << endl;
      }
    }
    else {
      cout << "NO" << endl;
    }    
  }
  else {
    cout << "NO" << endl;
  }  
}
