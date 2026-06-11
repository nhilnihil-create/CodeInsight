#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,X;
  cin>>N>>X;
  int minD=X;
  rep(i,N){
    int I;
    cin>>I;
    X-=I;
    minD=min(minD,I);
  }
  int ans=N+(X/minD);
  cout<<ans<<endl;
}