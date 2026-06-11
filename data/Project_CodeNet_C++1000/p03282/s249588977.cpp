#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  int K;
  cin>>S>>K;
  for(int i=0;i<min((int)S.size(),K);i++){
    if(S[i]!='1'){
      cout<<S[i]<<endl;
      return 0;
    }
  }
  cout<<1<<endl;
}