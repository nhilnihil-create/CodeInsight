#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int count=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='o'){
      count++;
    }
  }
  if(8-count<=15-S.size()){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
