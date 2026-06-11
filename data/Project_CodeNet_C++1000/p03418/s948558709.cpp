#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  int64_t ans=0;
  if(K!=0){
  for(int b=K+1;b<=N;++b){
    int d=N-K;
    int q=d/b;
    int r=d%b;
    ans += (b-K)*q+min(r+1,b-K);
  }
  }
  else ans=int64_t(N)*int64_t(N);
  
  cout<<ans<<endl;
}
