#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;

  string T="";
  for(int i=0;i<S.size();i++){
    if(S.at(i)!='x')  T+=S.at(i);
  }
  for(int i=0;i<T.size()/2;i++){
    if(T.at(i)!=T.at(T.size()-1-i)){
      cout << -1 << endl;
      return 0;
    }
  }

  int l=0;
  int r=S.size()-1;
  int ans=0;
  while(l<r){
    if(S.at(l)==S.at(r)){
      l++;
      r--;
      continue;
    }
    if(S.at(l)=='x'){
      ans++;
      l++;
      continue;
    }
    if(S.at(r)=='x'){
      ans++;
      r--;
      continue;
    }
  }
  cout << ans << endl;

  return 0;
}