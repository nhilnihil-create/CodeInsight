#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t;  cin >> s >> t;
  for(int i=s.size()-1; i+1>=t.size(); i--){
    bool ok = true;
    for(int j=t.size()-1; j>=0; j--){
      if(t[j] == s[i-(int)(t.size())+1+j] || s[i-(int)(t.size())+1+j] == '?'){
      }else{
	ok = false;
	break;
      }
    }
    if(ok){
      for(int j=0; j+t.size()<i+1; j++)  printf("%c", s[j]=='?' ? 'a' : s[j]);
      cout << t;
      for(int j=i+1; j<s.size(); j++)  printf("%c", s[j]=='?' ? 'a' : s[j]);
      cout << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE\n";
  return 0;
}
