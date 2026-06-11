#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,H;
  cin>>N>>H;
  vector<pair<int,int>> A(N*2);
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    A[i]=make_pair(a,0),A[N+i]=make_pair(b,1);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  int j=0;
  for(pair<int,int> p:A){
    if(p.second==0){
      cout<<j+(H+p.first-1)/p.first<<endl;
      return 0;
    }
    j++,H-=p.first;
    if(H<=0){
      cout<<j<<endl;
      return 0;
    }
  }
}