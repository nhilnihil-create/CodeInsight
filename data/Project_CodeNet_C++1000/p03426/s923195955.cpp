#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 100

int main(){
  int H,W,D;
  cin>>H>>W>>D;
  vector<vector<int>> A(H,vector<int>(W));
  vector<pair<int,int>> xy(H*W);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A.at(i).at(j);
      xy.at(A.at(i).at(j)-1)=make_pair(i,j);
    }
  }
  vector<int> cost(H*W,0);
  for(int i=0;i<H*W-D;i++){
    cost.at(i+D)=cost.at(i)+abs(xy.at(i+D).first-xy.at(i).first)+abs(xy.at(i+D).second-xy.at(i).second);
  }
  int Q;
  cin>>Q;
  vector<int> L(Q),R(Q);
  for(int i=0;i<Q;i++){
    cin>>L.at(i)>>R.at(i);
  }
  for(int i=0;i<Q;i++){
    cout<<cost.at(R.at(i)-1)-cost.at(L.at(i)-1)<<endl;
  }
}
