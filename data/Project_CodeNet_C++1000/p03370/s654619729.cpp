#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,X;
  cin>>N>>X;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end());
  
  
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=vec[i];
  }
  
  int x=X-sum;
  
  int ans=0;
  
  while(x>=vec[0]){
    x-=vec[0];
    ans++;
  }
  
  
  cout<<ans+N<<endl;
}