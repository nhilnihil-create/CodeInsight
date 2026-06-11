#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll H,W,D;
  cin>>H>>W>>D;
  unordered_map<int,pair<int,int>> pos;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      int a;
      cin>>a;
      pos[a]=make_pair(i,j);
    }
  }
  int Q;
  cin>>Q;
  int A[Q][2];
  for(int i=0; i<Q; i++){
    int L,R;
    cin>>L>>R;
    A[i][0]=L;
    A[i][1]=R;
  }
//DP
  int DP[H*W+1];
  DP[0]=0;
  for(int k=1; k<=D; k++){
    int d=D;
    DP[k]=0;
    while(k+d<=H*W){
      int tmp=0;
      tmp+=abs(pos[k+d].first-pos[k+d-D].first);
      tmp+=abs(pos[k+d].second-pos[k+d-D].second);
      DP[k+d]=DP[k+d-D]+tmp;
      d=d+D;
    }
  }
  
  for(int i=0; i<Q; i++){
    int ans=DP[A[i][1]]-DP[A[i][0]];
    cout<<ans<<endl;
  }
}
