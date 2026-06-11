#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,M,X;
  cin>>N>>M>>X;
  vector<int> charge(M);
  rep(i,M)cin>>charge[i];
  int toZ=0,toN=0;
  rep(i,M){
    if(charge[i]<X)toZ+=1;
    if(charge[i]>X)toN+=1;
  }
  cout<<min(toZ,toN)<<endl;
  return 0;
}