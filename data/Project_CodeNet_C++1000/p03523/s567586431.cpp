#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  string s,ans="AKIHABARA";
  int j=0;
  cin>>s;
  if(s.size()>9) cout<<"NO"<<endl;
  else{
  for(int i=0;i<ans.size();){
    if(s[i]!=ans[j]){
      if(ans[j]!='A'){
        cout<<"NO"<<endl;
        break;
      }else i--;
    }
    i++;
    j++;
    if(j==ans.size()) cout<<"YES"<<endl;
  }
  }
}