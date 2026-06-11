#include<bits/stdc++.h>
using namespace std;


int main(){
  
  map<char, int> S;
  for(int i = 0; i < 3; i++){
    char s;
    cin >> s;
    S[s]++;
  }
  
  if(S['a'] == 1 && S['b'] == 1 && S['c'] == 1){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}