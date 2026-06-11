#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;
  string S = to_string(N);
  string ans = "";
  for (int i = 0; i < S.size(); i++){
    if (S.at(i) == '9') cout << '1';
    if (S.at(i) == '1') cout << '9';
  }
  cout << "" << endl;
}