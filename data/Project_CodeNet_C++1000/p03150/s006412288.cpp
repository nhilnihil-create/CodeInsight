#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  bool ok=false;
  for(int i=0;i<s.size();i++){
    for(int j=i;j<s.size();j++){
      string t=s.substr(0,i)+s.substr(j);
      if(t=="keyence")ok=true;
    }
  }
  if(ok){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
  