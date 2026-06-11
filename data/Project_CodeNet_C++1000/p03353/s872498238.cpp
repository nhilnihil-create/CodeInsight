#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int k;
  cin >> s >> k;
  int n = s.length();
  int i,j;
  set<string>str;
  for(i=0;i<n;i++){
    for(j=1;i+j<=n && j <= k;j++){
      str.insert(s.substr(i,j));
    }
  }
  i = 1;
  for(auto kk:str){
    if(i==k){
      cout << kk << endl;
      break;
    }
    i++;
  }
}
