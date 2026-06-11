#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string S;
  char rS='a'-1;
  cin >> S;
  set<char> alp;
  set<char> word;
  set<char> res;
  string resS="";
  int flag=0;
  
  for(char s='a';s<='z';s++) alp.insert(s);
  while(flag==0){
    word.clear();
    res.clear();
    if (S.empty()) flag=1;
    for(auto itr=S.begin();itr!=S.end();itr++) word.insert(*itr);
    set_difference(alp.begin(),alp.end(),
                   word.begin(),word.end(),
                   inserter(res,res.end()));
    for(auto itr=res.begin();itr!=res.end();itr++){
      if(*itr>rS){
        resS=S;
        resS.push_back(*itr);
        flag=1;
        break;
      }
    }
    
    if(flag==1) break;
    rS = *(S.end()-1);
    S.pop_back();
  }
  if(resS.empty()){cout << -1 << endl;}
  else{ cout << resS << endl;}
}