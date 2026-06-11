#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int D,N;
  cin>>D>>N;
  int ans=0;
  if(N==100)N+=1;
  if(D==0)ans=N;
  if(D==1)ans=N*100;
  if(D==2)ans=N*10000;
  cout<<ans<<endl;
}