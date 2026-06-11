#include<iostream>
#include<vector>
#include<cmath>
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
  int64_t N;
  cin>>N;
  std::vector<int64_t> L(N+1);
  L[0]=2;
  L[1]=1;
  for(int i=2;i<=N;i++)
    L[i]=L[i-1]+L[i-2];
  cout<<L[N]<<endl;
  return 0;
}
