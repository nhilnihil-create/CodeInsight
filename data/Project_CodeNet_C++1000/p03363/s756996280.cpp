#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N,count=1;
  cin>>N;
  ll ans=0;
  vector<ll> A(N);
  vector<ll> B(N+1);
  B.at(0)=0;
  for(int i=0; i<N; i++){
    cin>>A.at(i);
  }
  for(int i=1; i<N+1; i++){
    B.at(i)=A.at(i-1)+B.at(i-1);
  }
  sort(B.begin(),B.end());
  for(int i=1; i<=N; i++){
    if(B.at(i)==B.at(i-1)){
      ans+=count;
      count++;//連続で同じ数が続いたら、nC2=n(n-1)/2=1+2+…+(n-1)と増えていく
    }
    else{
      count=1;
    }
  }
  cout<<ans<<endl;
}