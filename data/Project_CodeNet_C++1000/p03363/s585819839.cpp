#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  long long A[N];
  long long S[N+1];
  S[0]=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    S[i+1]=S[i]+A[i];
  }
  sort(S,S+N+1);
  map<long long,long long>mp;
  for(int i=0;i<N+1;i++){
    mp[S[i]]++;
  }
  long long ans=0;
  for(auto itr=mp.begin();itr !=mp.end();itr++){
    long long temp=itr->second;
    if(temp>1){
      ans+=temp*(temp-1)/2;
    }
  }
  cout<<setprecision(18)<<ans<<endl;
  return 0;
}
