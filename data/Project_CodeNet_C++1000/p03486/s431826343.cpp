#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end(),greater<int>());
  for(int i=0; i<s.length(); i++){
    if(s[i]<t[i]){
      cout << "Yes" << endl;
      return 0;
    }else if(s[i]>t[i]){
      cout << "No" << endl;
      return 0;
    }
  }
  if(s.length()<t.length()) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}