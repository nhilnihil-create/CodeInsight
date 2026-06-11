#include <bits/stdc++.h>

using namespace std;


int main(){
  string s,t;
  cin>>s>>t;
  int size = s.size()>=t.size() ? s.size() : t.size();
  string lcs = "";
  int LCS[s.size()+1][t.size()+1];
  for(int i=0;i<=s.size();i++){
    for(int j=0;j<=t.size();j++){
        if(i ==0 || j==0)
          LCS[i][j] =0;
        else if(s[i-1] == t[j-1]){
          LCS[i][j] = 1 +LCS[i-1][j-1];
        }
        else{
            LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
        }
    }
  }
  int i=s.size(),j=t.size();
  while(i>0 && j>0){
     if(s[i-1] == t[j-1]){
       lcs = s[i-1] + lcs;
       i--;
       j--;
     }
     else{
       if(LCS[i-1][j]>LCS[i][j-1]){
         i--;
       }
       else
        j--;
     }

  }
  cout<<lcs;

  return 0;
}
