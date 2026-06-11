#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>> A(N);
  for(pair<int,int> &p:A)
    cin>>p.first>>p.second;
  sort(A.begin(),A.end());
  int ans=0,cnt=0;
  for(int i=0;cnt<M;i++){
    ans+=A[i].first*min(A[i].second,M-cnt);
    cnt+=A[i].second;
  }
  cout<<ans<<endl;
}