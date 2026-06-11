#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  
  vector<int>count(S.size(),0);
  for (int i = 0; i < S.size(); i++) {
    for (int j = i; j < S.size(); j++) {
      if (S.at(j) == 'A' || S.at(j) == 'C' || S.at(j) == 'G' || S.at(j) == 'T'){
        count.at(i)++;
      }
      else {
        break;
      }
    }
  }
  sort(count.begin(), count.end());
  cout << count.at(S.size()-1) << endl;
}
  