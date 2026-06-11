#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(int)(n);i++)
signed main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans=0;
  if(A+B<=C*2){
    ans+=A*X;
    ans+=B*Y;
    }
  else{
    if(X>Y){
      ans+=Y*C*2;
      ans+=min((X-Y)*C*2,(X-Y)*A);
      }
    else{
      ans+=X*C*2;
      ans+=min((Y-X)*B,(Y-X)*C*2);
      }
    }
  cout<<ans<<endl;
  }