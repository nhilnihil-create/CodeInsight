#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  cin>>s;
  if(s=="keyence"){
    cout<<"YES"<<endl;
    return 0;
  }
  for(int i=0;i<s.size()-1;i++){
    for(int j=i;j<s.size();j++){
      string p="";
      for(int k=0;k<s.size();k++){
        if(k<i||j<k){
          p+=s[k];
        }
      }
      if(p=="keyence"){
        cout<<"YES"<<endl;
        return 0;
      }
    }
  }
  cout<<"NO"<<endl;
}