#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,M;
  cin>>N>>M;
  int64_t sum=0;
  map<int64_t,int64_t> m;
  for(int i=0;i<N;++i){
    int64_t A;
    cin>>A;
    sum += A;
    sum %= M;
    ++m[sum];
  }
  ++m[0];
  
  sum=0;
  for(auto p:m) sum += ((p.second-1)*p.second)/2;
  cout<<sum<<endl;
}
