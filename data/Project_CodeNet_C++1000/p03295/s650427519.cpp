#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>> A(M);
  for(pair<int,int> &p:A)
    cin>>p.first>>p.second;
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  int n=N+1,ans=0;
  for(int i=0;i<M;i++){
    if(A[i].second<n+1){
      n=A[i].first;
      ans++;
    }
  }
  cout<<ans<<endl;
}