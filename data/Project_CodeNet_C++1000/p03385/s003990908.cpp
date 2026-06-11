#include <bits/stdc++.h>
using namespace std;

int main(){
  set<int> s;
  string S;
  cin >> S;
  for(int i=0;i<3;i++){
    s.insert(S.at(i));
  }
  if(s.size()==3){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
