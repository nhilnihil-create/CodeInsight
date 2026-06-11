#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  int N=S.length();
  int l=0,r=N-1;
  int ans=0;
  while(l<r){
    if(S[l]==S[r]){l++;r--;}
    else{
      if(S[l]=='x'){ans++;l++;}
      else if(S[r]=='x'){ans++;r--;}
      else {
        cout<<-1;
        return 0;
      }
    }
  }
  cout<<ans;
}