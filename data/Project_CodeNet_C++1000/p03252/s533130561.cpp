#include<iostream>
#include<string>
using namespace std;
int main(){
  string s,t;cin >> s >> t;bool ok = true;
  int n = t.size(),i,j;int als[26],alt[26];
  for(i=0;i<26;i++) als[i] = alt[i] = -1;
  for(i=0;i<n;i++){
    if(als[s[i]-'a'] >= 0 && als[s[i]-'a'] != t[i]-'a'){
      cout << "No" << endl;return 0;
    } else als[s[i]-'a'] = t[i]-'a';
    if(alt[t[i]-'a'] >= 0 && alt[t[i]-'a'] != s[i]-'a'){
      cout << "No" << endl;return 0;
    } else alt[t[i]-'a'] = s[i]-'a';
  }
  cout << "Yes" << endl;
}