#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  rep(i,3){
    if(S[i]=='1')S[i]='9';
    else S[i]='1';
  }
  cout<<S<<endl;
  return 0;
}