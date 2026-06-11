#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  int A=0,B=0;
  rep(i,S.size()){
    if(S[i]=='0')A+=1;
    else B+=1;
  }
  cout<<2*min(A,B)<<endl;
}