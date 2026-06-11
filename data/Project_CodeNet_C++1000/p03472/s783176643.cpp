#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
  long long N,H,ans=0;
  cin >>N>>H;
  long long a,b,a_max=0;
  vector<long long> V;
  
  for(long long i=0;i<N;i++){
    cin>>a>>b;
    a_max=max(a,a_max);
    V.push_back(b);
  }
  
  sort(V.begin(), V.end());
  
  for(long long i=0;i<N;i++){
    if(a_max<V[N-i-1]){
      H-=V[N-i-1];
      ans+=1;
    }
    if(H<=0)break;
  }
  
  if(H>0){
    ans+=ceil(H*1.0/a_max);
  }
  cout<<ans<<endl;
}