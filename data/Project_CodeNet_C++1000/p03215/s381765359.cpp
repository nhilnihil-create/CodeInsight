#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 998244353

int main(){
  int N,K;
  cin>>N>>K;
  vector<ll> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }

  vector<ll> sum(N+1,0);
  for(int i=0;i<N;i++){
    sum.at(i+1)=sum.at(i)+a.at(i);
  }

  vector<vector<int>> beau(N*(N+1)/2,vector<int>(42));
  int index=0;
  for(int i=0;i<N;i++){
    for(int j=i;j<N;j++){
      ll A=sum.at(j+1)-sum.at(i);
      for(int k=0;k<42;k++){
        beau[index][k]+=A%2;
        A/=2;
      }
      index++;
    }
  }

  N=N*(N+1)/2;
  ll ans=0;
  ll res=1ull<<42;
  vector<bool> to_be_seen(N,true);
  for(int j=41;j>=0;j--){
    res>>=1;
    int count=0;
    for(int i=0;i<N;i++){
      if(to_be_seen.at(i)){
        count+=beau.at(i).at(j);
      }
    }
    if(count<K){
      continue;
    }
    ans+=res;
    for(int i=0;i<N;i++){
      if(beau.at(i).at(j)==0){
        to_be_seen.at(i)=false;
      }
    }
  }
  cout<<ans<<endl;
}
