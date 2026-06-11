#include <bits/stdc++.h>
using namespace std;


int main() {
  int n; cin >> n;
  string S[n];
  for(int i = 0; i < n; i++) cin >> S[i];
  char s = S[0][0];
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++){
      if(S[i] == S[j]){
        cout << "No" << endl;
        return 0;
      }
    } 
  for(int i = 0; i < n; i++){
    if(S[i][0] != s){
      cout << "No" << endl;
      return 0;
    }
    s = S[i][S[i].size()-1];
  }
  cout << "Yes" << endl;
}
