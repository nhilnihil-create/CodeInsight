#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i;
  if(s == "zyxwvutsrqponmlkjihgfedcba")cout << -1 << endl;
  else{
    if(s.length() <26){
      vector<bool>alp(26,false);
      for(i=0;i<s.length();i++){
        alp[(int)(s[i]-'a')]=true;
      }
      for(i=0;i<26;i++){
        if(alp[i]==false){
          s += (char)(i+'a');
          break;
        }
      }

      cout << s << endl;
    }else{
      string ssub = s;
      next_permutation(s.begin(),s.end());
      for(i=0;i<26;i++){
        if(s[i] == ssub[i])cout<<s[i];
        else{
           cout << s[i] << endl;
           break;
        }

      }
    }
  }
}
