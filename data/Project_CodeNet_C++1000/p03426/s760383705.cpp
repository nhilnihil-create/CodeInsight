#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int H,W,D,Q;
  cin>>H>>W>>D;
  vector<pair<int,int>> A(H*W+1);
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      int a;
      cin>>a;
      A[a].first=i,A[a].second=j;
    }
  vector<int> B(H*W+1);
  for(int i=D+1;i<=H*W;i++)B[i]=B[i-D]+abs(A[i].first-A[i-D].first)+abs(A[i].second-A[i-D].second);
  cin>>Q;
  while(Q--){
    int a,b;
    cin>>a>>b;
    cout<<B[b]-B[a]<<endl;
  }
}