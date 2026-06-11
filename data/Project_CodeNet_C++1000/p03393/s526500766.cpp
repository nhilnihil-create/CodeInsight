#include <bits/stdc++.h>
using namespace std;

int main(){
 
  string S,ans="";
  cin >> S;
  
  bool f = false;
  
  if (S == "zyxwvutsrqponmlkjihgfedcba") ans = "-1";
  else{
    if (S.length()<26){
      for(int i='a';i<'z'+1;i++){
      for(auto &v:S){
        if(i==v){
         break;
        }
        if (v==S[S.length()-1]){
          f = true;
          ans = S + (char)i;
        }
      } 
      if (f) break;
      }
      }else{
          int pos = -1;
          int min_str = 1 + 'z';
        for(int i=24;i>=0;i--){
            if(S[i] < S[i+1]){
                for(int j = i + 1;j<26;j++){
                 if(S[i] < S[j])min_str = min(min_str,(int)S[j]); 
                }
                pos = i;
                S[i] = (char)min_str;
                break;
            }
        }
        for(int i=0;i<pos+1;i++){
            ans += S[i];
        }
    }
    }  
  
  cout << ans << endl;
  
  
}
