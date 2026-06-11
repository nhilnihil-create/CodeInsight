#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=1000;
  for(int i=0;i<s.size()-2;i++){
    int a=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
    int b;
    if(a>=753){
      b=a-753;
    }
    else{
      b=753-a;
    }
    if(b<ans){
      ans=b;
    }
  }
  cout<<ans<<endl;
}