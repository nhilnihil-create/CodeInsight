#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,H;cin>>N>>H;
  vector<pair<int,int>>A(N*2);
  for(int i=0;i<N;i++){
    int a,b;cin>>a>>b;
    A[i*2]=pair(a,1);
    A[i*2+1]=pair(b,2);
  }
  sort(A.rbegin(),A.rend());
  long long count=0;
  for(int i=0;i<N*2;i++){
    if(A[i].second==1){
      cout<<i+(H-count+A[i].first-1)/A[i].first<<endl;
      return 0;
    }
    count+=A[i].first;
    if(count>=H){cout<<i+1<<endl;return 0;}
  }
}