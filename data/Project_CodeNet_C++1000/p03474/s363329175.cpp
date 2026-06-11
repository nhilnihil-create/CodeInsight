#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  string S;
  cin >> A >> B >> S;
  vector<char> a = {'0','1','2','3','4','5','6','7','8','9'};
  int count = 0;
  if(S.at(A) != '-'){
    cout << "No" << endl;
    return 0;
  }
  for(int i = 0; i < A; i++){
    for(int j = 0; j < 10; j++){
      if(S.at(i) == a.at(j)){
        count++;
      }
    }
  }
  if(count != A){
    cout << "No" << endl;
    return 0;
  }
  count = 0;
  for(int i = A + 1; i < A + B + 1; i++){
    for(int j = 0; j < 10; j++){
      if(S.at(i) == a.at(j)){
        count++;
      }
    }
  }
  if(count != B){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;  
}
