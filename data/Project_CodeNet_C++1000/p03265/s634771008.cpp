#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<pair<int,int>> A(5);
  //A.at(0)=make_pair(0,0);
  for(int i=1;i<=2;i++){
    int x,y;cin>>x>>y;
    A.at(i)=make_pair(x,y);
  }
  for(int i=3;i<=4;i++){
    int X=A[i-2].second+A[i-1].first-A[i-1].second;
    int Y=A[i-1].first+A[i-1].second-A[i-2].first;
    A[i]=make_pair(X,Y);
  }
  for(int j=3;j<=4;j++) cout<<A[j].first<<" "<<A[j].second<<" ";
  cout<<"\n";
}
    
  