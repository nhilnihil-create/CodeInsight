#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  char tmp;
  cin >> S >> T;
  for(int i = 0; i < S.size(); i++){
    if(S == T){
      cout << "Yes" << endl;
      return 0;
    }
    else{
      tmp = S[0];
      S.erase(0,1);
      S.push_back(tmp);
    } 
  }
  cout << "No" << endl;
      
}