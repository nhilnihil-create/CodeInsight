#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  for(int bi=0;bi<8;bi++){
    int ans=S[0]-'0';
    for(int i=0;i<3;i++){
      if((bi>>i) & 1)ans+=S[i+1]-'0';
      else ans-=S[i+1]-'0';
    }
    if(ans==7){
      cout<<S[0];
      if((bi>>0) & 1)cout<<'+';
      else cout<<'-';
      cout<<S[1];
      if((bi>>1) & 1)cout<<'+';
      else cout<<'-';
      cout<<S[2];
      if((bi>>2) & 1)cout<<'+';
      else cout<<'-';
      cout<<S[3];
      cout<<"=7\n";
      return 0;
    }
  }
}