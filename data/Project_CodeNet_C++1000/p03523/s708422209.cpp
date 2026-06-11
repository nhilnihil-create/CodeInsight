#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;

  string T="AKIHABARA";
  vector<bool> ok(T.size(),false);
  int now=0;
  for(int i=0;i<S.size();i++){
    bool flag=false;
    for(;now<T.size();now++){
      if(S.at(i)==T.at(now)){
        flag=true;
        ok.at(now)=true;
        now++;
        break;
      }
    }
    if(!flag){
      cout << "NO" << endl;
      return 0;
    }
  }
  for(int i=0;i<T.size();i++){
    if(ok.at(i))  continue;
    if(T.at(i)=='A')  continue;
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;

  return 0;
}