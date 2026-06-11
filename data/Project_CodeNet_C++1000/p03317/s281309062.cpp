#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  if((N-1)%(K-1)==0){
    cout<<(N-1)/(K-1)<<endl;
  }
  else{
    cout<<(N-1)/(K-1)+1<<endl;
  }
}
