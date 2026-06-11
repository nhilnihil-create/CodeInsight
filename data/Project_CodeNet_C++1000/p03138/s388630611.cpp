#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007

int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  sort(A.begin(),A.end());
  vector<vector<int>> a(N);
  if(A.at(N-1)>0){
    while(A.at(N-1)>0){
      for(int i=0;i<N;i++){
        a.at(i).push_back(A.at(i)&1);
        A.at(i)>>=1;
      }
    }
  }else{
    for(int i=0;i<N;i++){
      a.at(i).push_back(0);
    }
  }
  int n=a.at(N-1).size();
  for(int i=0;i<N;i++){
    reverse(a.at(i).begin(),a.at(i).end());
  }
  vector<int> count(n,0);
  for(int i=0;i<n;i++){
    for(int j=0;j<N;j++){
      count.at(i)+=a.at(j).at(i);
    }
  }
  vector<int> k;
  if(K>0){
    while(K>0){
      k.push_back(K&1);
      K>>=1;
    }
  }else{
    k.push_back(0);
  }
  reverse(k.begin(),k.end());
  int m=k.size();

  if(m>n){
    ll res=1ull<<(m-1);
    vector<vector<ll>> dp(m,vector<ll>(2,0));
    if(a.at(N-1).at(0)!=0){
      dp.at(0).at(0)=N*res;
    }
    dp.at(0).at(1)=0;
    res>>=1;
    for(int i=1;i<m-n;i++){
      if(k.at(i)==0){
        dp.at(i).at(0)=dp.at(i-1).at(0);
        dp.at(i).at(1)=dp.at(i-1).at(1)+res*N;
      }else{
        dp.at(i).at(0)=dp.at(i-1).at(0)+res*N;
        dp.at(i).at(1)=max<ll>(dp.at(i-1).at(1)+res*N,dp.at(i-1).at(0));
      }
      res>>=1;
    }
    for(int i=m-n;i<m;i++){
      if(k.at(i)==0){
        dp.at(i).at(0)=dp.at(i-1).at(0)+res*(ll)count.at(i-m+n);
        dp.at(i).at(1)=dp.at(i-1).at(1)+res*max<ll>(count.at(i-m+n),N-count.at(i-m+n));
      }else{
        dp.at(i).at(0)=dp.at(i-1).at(0)+res*(N-(ll)count.at(i-m+n));
        dp.at(i).at(1)=max<ll>(dp.at(i-1).at(1)+res*max<ll>(count.at(i-m+n),N-count.at(i-m+n)),dp.at(i-1).at(0)+res*(ll)count.at(i-m+n));
      }
      res>>=1;
    }
    cout<<max<ll>(dp.at(m-1).at(0),dp.at(m-1).at(1))<<endl;
  }else if(n>m){
    vector<vector<ll>> dp(n,vector<ll>(2,0));
    ll res=(1ull<<(n-1));
    dp.at(0).at(0)=res*(ll)count.at(0);
    res>>=1;
    for(int i=1;i<n-m;i++){
      dp.at(i).at(0)=dp.at(i-1).at(0)+res*(ll)count.at(i);
      res>>=1;
    }
    for(int i=n-m;i<n;i++){
      if(k.at(i-n+m)==0){
        dp.at(i).at(0)=dp.at(i-1).at(0)+res*(ll)count.at(i);
        dp.at(i).at(1)=dp.at(i-1).at(1)+res*max<ll>(count.at(i),N-count.at(i));
      }else{
        dp.at(i).at(0)=dp.at(i-1).at(0)+res*(N-(ll)count.at(i));
        dp.at(i).at(1)=max<ll>(dp.at(i-1).at(1)+res*max<ll>(count.at(i),N-count.at(i)),dp.at(i-1).at(0)+res*(ll)count.at(i));
      }
      res>>=1;
    }
    cout<<max<ll>(dp.at(n-1).at(0),dp.at(n-1).at(1))<<endl;
  }else{
    vector<vector<ll>> dp(n,vector<ll>(2,0));
    ll res=(1ull<<(n-1));
    if(k.at(0)==1){
      dp.at(0).at(0)=res*(N-(ll)count.at(0));
      dp.at(0).at(1)=res*(ll)count.at(0);
    }else{
      dp.at(0).at(0)=res*(ll)count.at(0);
    }
    res>>=1;
    for(int i=1;i<n;i++){
      if(k.at(i)==0){
        dp.at(i).at(0)=dp.at(i-1).at(0)+res*(ll)count.at(i);
        dp.at(i).at(1)=dp.at(i-1).at(1)+res*max<ll>(count.at(i),N-count.at(i));
      }else{
        dp.at(i).at(0)=dp.at(i-1).at(0)+res*(N-(ll)count.at(i));
        dp.at(i).at(1)=max<ll>(dp.at(i-1).at(1)+res*max<ll>(count.at(i),N-count.at(i)),dp.at(i-1).at(0)+res*(ll)count.at(i));
      }
      res>>=1;
    }
    cout<<max<ll>(dp.at(n-1).at(0),dp.at(n-1).at(1))<<endl;

  }

}
