#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
  string s;cin >> s;
  if(s == "zyxwvutsrqponmlkjihgfedcba"){
    cout << "-1\n";return 0;
  }
  int n = s.size(),i,j;
  bool use[26] = {};
  for(i=0;i<n;i++) use[s[i]-'a'] = true;
  for(i=0;i<26;i++){
    if(!use[i]){
      cout << s << char(i+'a') << "\n";return 0;
    }
  }
  for(i=n-2;i>=0;i--){
    if(s[i] < s[i+1]){
      for(j=i+1;j<n;j++) use[s[j]-'a'] = false;
      s = s.substr(0,i+1);
      while(use[s[s.size()-1]-'a']) s[s.size()-1]++;
      cout << s << "\n";
      return 0;
    }
  }
}