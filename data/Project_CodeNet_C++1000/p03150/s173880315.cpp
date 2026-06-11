#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
  string s;
  cin>>s;
  string t="keyence";
  
   for(int i=0;i<s.size();i++){
      for(int j=i;j<s.size();j++){
        string h;
        for(int k=0;k<s.size();k++){
          if(k>i&&k<j){continue;}
          else{h+=s[k];}
        }
        if(h==t){cout<<"YES"<<endl;return 0;}
   }
   }
   cout<<"NO"<<endl;
  return 0;}