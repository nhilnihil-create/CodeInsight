#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int b=0;
  int c=0; 
  while(b<N-1){
    c++;
    b+=K-1;
  }
  cout<<c<<endl;
  return 0;
}