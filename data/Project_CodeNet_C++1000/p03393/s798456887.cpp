#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  set<char> s;
  for(int i=0;i<S.size();i++){
    s.insert(S.at(i));
  }
  if(s.size()==26){
    set<char> b;
    for(int i=S.size()-1;i>=0;i--){
      for(char j=S.at(i)+1;j<='z';j++){
        if(b.count(j)){
          S.at(i)=j;
          S.erase(S.begin()+i+1,S.end());
          cout << S << endl;
          return 0;
        }
      }
      b.insert(S.at(i));
    }
    cout << -1 << endl;
    return 0;
  }
  for(char i='a';i<='z';i++){
    if(!s.count(i)){
      S+=i;
      break;
    }
  }
  cout << S << endl;
  return 0;
}
