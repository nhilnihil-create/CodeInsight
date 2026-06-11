#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S,T;
  cin >> S >> T;
  
  vector<int>numS(S.size());
  for (int i = 0; i < S.size(); i++) {
    numS.at(i) = S.at(i) - '0';
  }
  
  vector<int>numT(T.size());
  for (int i = 0; i < T.size(); i++) {
    numT.at(i) = T.at(i) - '0';
  }
  
  vector<int>countS(26,0);
  for (int i = 0; i < S.size(); i++) {
    countS.at(numS.at(i)-49)++;
  }
  sort(countS.begin(), countS.end());
  
  vector<int>countT(26,0);
  for (int i = 0; i < T.size(); i++) {
    countT.at(numT.at(i)-49)++;
  }
  sort(countT.begin(), countT.end());
  
  for (int i = 0; i < 26; i++) {
    if (countS.at(i) != countT.at(i)){
      cout << "No" << endl;
      return 0;
    }
    else if (i == 25){
      cout << "Yes" << endl;
    }
  }
}
    
  