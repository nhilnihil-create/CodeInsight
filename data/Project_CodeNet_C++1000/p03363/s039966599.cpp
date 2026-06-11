#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<int> V(N);
  vector<int64_t> sum(N+1);
  for(int i=0;i<N;i++){
    cin>>V.at(i);
  }
  sum.at(0)=0;
  for(int i=1;i<N+1;i++){
    sum.at(i)=sum.at(i-1)+V.at(i-1);
  }
  sort(sum.begin(),sum.end());
  int64_t ans=0;
  int64_t num=0;
  for(int i=1;i<N+1;i++){
    if(sum.at(i)==sum.at(i-1)){
      num++;
    }
    else{
      ans=ans+num*(num+1)/2;
      num=0;
    }
  }
  ans=ans+num*(num+1)/2;
  cout<<ans;
}