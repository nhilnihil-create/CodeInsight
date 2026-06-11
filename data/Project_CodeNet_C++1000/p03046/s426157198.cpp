#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int M,K;
  cin>>M>>K;
  ll N=pow(2,M);
  if(M==0&&K==0){
    for(int i=0;i<N;i++)cout<<i<<" "<<i<<" ";
  }
  else if(M==1&&K==0){
    cout<<1<<" "<<1<<" "<<0<<" "<<0;
  }
  else if(M==1&&K==1){
    cout<<-1<<endl;
  }
  else if(N<=K){
    cout<<-1<<endl;
  }
  else{
    for(int i=0;i<N;i++){
      if(i==K)continue;
      cout<<i<<" ";
    }
    cout<<K<<" ";
    for(int i=N-1;i>=0;i--){
      if(i==K)continue;
      cout<<i<<" ";
    }
    cout<<K;
  }

  return 0;
}
