#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,T,A;
  cin>>N>>T>>A;
  
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  
  vector<double> ave(N);
  for(int i=0;i<N;i++){
    ave[i]=abs(A-(T-H[i]*0.006));
  }
  
  double mini=100000;
  
  
  for(int i=0;i<N;i++){
    mini=min(ave[i],mini);
  }
  
  for(int i=0;i<N;i++){
    if(mini==ave[i]){
      cout<<i+1<<endl;
      break;
    }
  }
}