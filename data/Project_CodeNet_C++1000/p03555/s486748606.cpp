#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<string> S(2);
  for (int i = 0; i < 2; i++){
    cin >> S.at(i);
  }
  if (S.at(0).at(0) == S.at(1).at(2) && S.at(0).at(1) == S.at(1).at(1) && S.at(0).at(2) == S.at(1).at(0)){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}