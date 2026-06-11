#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  cin>>S;
  int k=0,j=0;
  for(int i=0;i<S.size();i++){
    if(S[i]=='W'){
      k+=i-j;
      j++;
    }
  }
  cout<<k<<endl;
}