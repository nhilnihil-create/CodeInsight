#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,D;
  cin>>H>>W>>D;
  vector<pair<int,int>> p(H*W+1);
  p[0]=make_pair(0,0);
  for(int i=0;i<H;++i){
    for(int j=0;j<W;++j){
      int A;
      cin>>A;
      p[A]=make_pair(i,j);
    }
  }

  //余りがiの累積和をq[i]に入れる
  //q[i][j]=(iからi+j*Dまでの移動コスト)
  vector<vector<int>> q(D+1,vector<int>());
  for(int i=1;i<=D;++i){
    int j=i+D;
    int sum=0;
    q[i].push_back(0);
    while(j<=H*W){
      sum += abs(p[j].first-p[j-D].first)+abs(p[j].second-p[j-D].second);
      q[i].push_back(sum);
      j += D;
    }
  }

  int Q;
  cin>>Q;

  for(int i=0;i<Q;++i){
    int L,R;
    cin>>L>>R;
    if(L%D==0){
      int s=L/D,t=R/D;
      cout<<q[D][t-1]-q[D][s-1]<<endl;
    }
    else{
      int s=L/D,t=R/D,u=L%D;
      cout<<q[u][t]-q[u][s]<<endl;
    }
  }
}
