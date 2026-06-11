#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<pair<int,int>>A(100001);
  vector<pair<int,int>>B(100001);
  for(int i=0;i<100001;i++){
    A[i].second=i;
    B[i].second=i;
  }
  for(int i=0;i<N;i++){
    int a;cin>>a;
    if(i%2==0)A[a].first++;
    else B[a].first++;
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());
  if(A[0].second!=B[0].second)cout<<N-A[0].first-B[0].first<<endl;
  else cout<<min(N-A[0].first-B[1].first,N-A[1].first-B[0].first)<<endl;
}