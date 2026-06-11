#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,D,X;
  cin>>N>>D>>X;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  vector<int> sum(N);
  
  
  for(int i=0;i<N;i++){
    int day=1;
    while(day<=D){
      sum[i]++;
      day+=A[i];
    }
  }
  
  int ans=0;
  for(int i=0;i<N;i++){
    ans+=sum[i];
  }
  
  cout<<X+ans<<endl;
}