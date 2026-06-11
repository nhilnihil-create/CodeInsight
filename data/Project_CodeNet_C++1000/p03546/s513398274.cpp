#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int H,W;
  cin>>H>>W;
  vector<vector<int>> A(10,vector<int>(10)),B(H,vector<int>(W));
  vector<int> C={0,1,2,3,4,5,6,7,8,9},D(10,1000000000);
  for(vector<int> &v:A)
    for(int &i:v)
      cin>>i;
  D[1]=0;
  do{
    if(C[0]==1)
      continue;
    int cnt=0;
    for(int i=0;i<10;i++){
      cnt+=A[C[i]][C[i+1]];
      if(C[i+1]==1)
        break;
    }
    D[C[0]]=min(D[C[0]],cnt);
  }while(next_permutation(C.begin(),C.end()));
  int ans=0;
  for(vector<int> &v:B)
    for(int &i:v){
      cin>>i;
      if(i!=-1)
        ans+=D[i];
    }
  cout<<ans<<endl;
}