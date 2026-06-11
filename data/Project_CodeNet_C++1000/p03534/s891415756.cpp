#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int s[3]={};
  for(int i=0;i<S.size();i++){
    s[S[i]-'a']++;
  }
  int mx=0;
  mx=min(s[0],s[1]);
  mx=min(mx,s[2]);

  for(int i=0;i<3;i++){
    s[i]=s[i]-mx;
  }
  if(s[0]>=2||s[1]>=2||s[2]>=2){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
  return 0;
}
