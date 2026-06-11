#include<bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='1'){
      cout<<9<<flush;
    }else if(s[i]=='9'){
      cout<<1<<flush;
    }else{
      cout<<s[i]<<flush;
    }
  }
  cout<<endl;
}