#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,K;
  cin>>N>>K;
  
  vector<long long> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  long long dis=10000000000;
  for(int i=0;i<N-K+1;i++){
    long long temp=vec.at(i+K-1)-vec.at(i);
    dis=min(temp,dis);
  }
  cout<<dis<<endl;
}