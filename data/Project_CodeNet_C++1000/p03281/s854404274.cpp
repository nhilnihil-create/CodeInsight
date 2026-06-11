#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=1;i<=N;i++)

signed main(){
  int N;
  cin>>N;
  int ans=0;
  rep(i,N){
    int yaku=0;
    rep(j,i){
      if(i%j==0)yaku+=1;
    }
    if(i%2==1&&yaku==8)ans+=1;
  }
  cout<<ans<<endl;
  return 0;
}