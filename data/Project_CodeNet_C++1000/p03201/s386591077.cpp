#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  map<int,int> A;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[a]++;
  }
  int ans=0;
  while(A.size()){
    int j=(*prev(A.end())).first,k=1;
    for(;k<j;k*=2);
    if(k==j){
      ans+=A[j]/2;
      A.erase(j);
      continue;
    }
    if(A.count(k-j)){
      A[k-j]--;
      if(!A[k-j])A.erase(k-j);
      ans++;
    }
    A[j]--;
    if(!A[j])A.erase(j);
  }
  cout<<ans<<endl;
}