#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  cin>>S;
  if(S.size()!=26){
    set<char> A;
    for(char c:S)
      A.insert(c);
    for(char c='a';c<='z';c++)
      if(!A.count(c)){
        cout<<S<<c<<endl;
        return 0;
      }
  }else{
    int i=24;
    for(;i>=0;i--)
      if(S[i]<S[i+1])
        break;
    if(i==-1){
      puts("-1");
      return 0;
    }
    set<char> A;
    for(int j=0;j<i;j++){
      cout<<S[j];
      A.insert(S[j]);
    }
    for(char c=S[i]+1;c<='z';c++)
      if(!A.count(c)){
        cout<<c<<endl;
        return 0;
      }
  }
}