#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  if(S=="zyxwvutsrqponmlkjihgfedcba"){
    puts("-1");
    return 0;
  }
  if(S.size()!=26){
    cout<<S;
    vector<bool> A(26,true);
    for(char c:S)A[c-'a']=false;
    for(int i=0;i<26;i++)
      if(A[i]){
        cout<<(char)(i+'a')<<endl;
        return 0;
      }
  }
  int i=24;
  for(;i>=0;i--)
    if(S[i+1]>S[i])break;
  vector<bool> A(26,true);
  for(int j=0;j<i;j++){
    cout<<S[j];
    A[S[j]-'a']=false;
  }
  for(char c=S[i]+1;c<='z';c++){
    if(A[c-'a']){
      cout<<c<<endl;
      return 0;
    }
  }
}