#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s;
  cin >> N >> s;
  
  int countr = 0;
  int countb = 0;
  for(int i = 0; i < N; i++){
    if(s[i] == 'R'){
      countr++;
    }else{
      countb++;
    }
  }
  if(countr > countb){
    cout << "Yes" << endl;;
  }else{
    cout << "No" << endl;
  }
  
  
  
  return 0;
}