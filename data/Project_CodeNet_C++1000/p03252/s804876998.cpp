#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  string S, T;
  cin >> S >> T;
  vector<int> vecS(30);
  vector<int> vecT(30);
  for(int i = 0; i < S.size(); i++){
    if(vecS[S[i]-'a'] == NULL){
      vecS[S[i]-'a'] = T[i]-'a';
    } else{
      if(vecS[S[i]-'a'] != T[i]-'a'){
        cout << "No" <<endl;
        return 0;
      }
    }
    if(vecT[T[i]-'a'] == NULL){
      vecT[T[i]-'a'] = S[i]-'a';
    } else{
      if(vecT[T[i]-'a'] != S[i]-'a'){
        cout << "No" <<endl;
        return 0;
      }
    }
  }
  cout << "Yes" <<endl;
  return 0;
}
