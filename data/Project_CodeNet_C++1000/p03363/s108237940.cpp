#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin>>N;
  vector<int64_t> K(N+1,0);
  for(int64_t i=0;i<N;i++){
    int64_t j;
    cin>>j;
    K[i+1]=K[i]+j;
  }
  sort(K.begin(),K.end());
  int64_t j=0,k=1000000001,l=0;
  for(int64_t i=0;i<=N;i++){
    if(k==K[i])
      l++;
    else{
      j+=l*(l-1)/2;
      k=K[i];
      l=1;
    }
  }
  cout<<j+l*(l-1)/2<<endl;
}