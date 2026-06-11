#include <bits/stdc++.h>
using namespace std;

int main(){
  string S; size_t K;
  cin >> S >> K;

  set<string> dict;
  for(size_t i=0; i<S.size(); i++){
    for(size_t len=1; len <= S.size()- i; len++){
      string str_ins= S.substr(i, len);
      dict.insert(str_ins);

      if(dict.size() > K){
        string str_tail= *rbegin(dict);
        dict.erase(str_tail);
        if(str_ins==str_tail){ break; }
      }
    }
  }
  string ans= *rbegin(dict);

  cout << ans << endl;
}