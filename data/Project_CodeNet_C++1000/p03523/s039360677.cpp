#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  set<char> s;
  s.insert('K');
  s.insert('B');
  s.insert('R');
  for(int i=0;i<S.size()-1;i++){
    if(S.at(i)=='A'){
      if(!s.count(S.at(i+1))){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  for(auto itr=S.begin();itr!=S.end();){
    if(*itr=='A'){
      itr=S.erase(itr);
    }else{
      itr++;
    }
  }
  if(S=="KIHBR"){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
