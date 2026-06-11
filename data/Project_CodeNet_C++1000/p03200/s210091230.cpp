#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  bool b_flag=0, w_flag=0;
  ll w_cnt=0;
  ll ans=0;
  rep(i,s.size()){
    if(s[i]=='B') b_flag=1;
    if(s[i]=='W'){
      w_flag=1;
      ans+=i;
      w_cnt++;
    }
  }
  if(b_flag==0||w_flag==0){
    ans=0;
  }else{
    ans=ans-(w_cnt*(w_cnt-1)/2);
  }
  cout<<ans<<endl;
}
