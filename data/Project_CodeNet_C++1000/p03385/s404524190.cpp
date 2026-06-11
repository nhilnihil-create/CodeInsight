#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S,ans="No";
  cin>>S;
  int A[3];
  rep(i,3)A[i]=0;
  rep(i,3){
    A[S[i]-'a']+=1;
  }
  if(A[0]==1&&A[1]==1&&A[2]==1)ans="Yes";
  cout<<ans<<endl;
}