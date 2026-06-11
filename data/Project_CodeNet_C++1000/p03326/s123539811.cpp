#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M;
  cin>>N>>M;
  vector<vector<int64_t>>A(3,vector<int64_t>(N));
  for(int i=0;i<N;i++){
  cin>>A.at(0).at(i);
    cin>>A.at(1).at(i);
    cin>>A.at(2).at(i);
   }int64_t ans=0;
  for(int bit=0;bit<(1<<3);bit++){
  vector<int64_t>B(N);
    for(int i=0;i<N;i++){
      int64_t x=A.at(0).at(i);
      int64_t y=A.at(1).at(i);
      int64_t z=A.at(2).at(i);
      int64_t b=x+y+z;
    for(int j=0;j<3;j++){
  if(bit&(1<<j))
    b-=2*A.at(j).at(i);
  } B.at(i)=b;
    } sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    int64_t pos=0;
    for(int k=0;k<M;k++)
      pos+=B.at(k);
    if(ans<pos)
      ans=pos;
  }cout<<ans<<endl;
     return 0;
}
