#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int ss=S.size();
  int ans=ss;
  char c=S[ss/2];
  for(int i=ss/2;i<ss;i++){
    if(S[ss-1-i]!=c||S[i]!=c){
      ans=i;break;
    }
  }
  cout<<ans<<endl;
}