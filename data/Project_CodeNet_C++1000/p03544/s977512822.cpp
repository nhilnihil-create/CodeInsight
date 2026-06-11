#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<long long> L(87);
  L[0]=2;
  L[1]=1;
  for(int i=2;i<87;i++){
    L[i]=L[i-1]+L[i-2];
  }
  
  cout<<L[N]<<endl;
}