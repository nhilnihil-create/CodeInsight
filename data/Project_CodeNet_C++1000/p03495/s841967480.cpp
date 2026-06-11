#include <bits/stdc++.h>
using namespace std;



int main(){
  int N,K;
  cin>>N>>K;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    vec.at(A-1)+=1;
  }
  sort(vec.begin(),vec.end());
  
  int sum=0;
  for(int i=0;i<N-K;i++){
    sum+=vec.at(i);
  }
  cout<<sum<<endl; 
  
}