#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  if(A==B)cout<<C<<endl;
  if(A==C)cout<<B<<endl;
  if(B==C)cout<<A<<endl;
  return 0;
}