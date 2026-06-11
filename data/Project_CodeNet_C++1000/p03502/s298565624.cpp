#include <bits/stdc++.h>
using namespace std;

int ctoi(char x){
  return x - '0';
}

int main() {
  string s; cin >> s;
  int N = stoi(s);
  
  int H=0;
  for(int i=0; i<s.size(); i++){
    H += ctoi(s[i]);
  }
  
  if(N%H==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}