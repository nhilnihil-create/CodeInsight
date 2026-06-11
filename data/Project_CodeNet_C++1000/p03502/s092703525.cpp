#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  int K=N,har=0;
  while(K>0){
    har+=K%10,K/=10;
  }
  if(N%har==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}