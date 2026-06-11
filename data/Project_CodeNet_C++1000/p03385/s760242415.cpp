#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  bool a = false;
  bool b = false;
  bool c = false;

  for (int i = 0; i < S.size(); i++){
    if (S.at(i) == 'a') a = true;
    if (S.at(i) == 'b') b = true;
    if (S.at(i) == 'c') c = true;
  }

  if (a && b && c){
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
}