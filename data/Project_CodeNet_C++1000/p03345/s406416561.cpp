#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C,K;
  cin>>A>>B>>C>>K;
  int ans=0;
  if(K%2==0){
    ans=A-B;
  }else{
    ans=B-A;
  }
  if(ans>=1000000000000000000){
    cout<<"Unfair"<<endl;
  }
  cout<<ans<<endl;
}