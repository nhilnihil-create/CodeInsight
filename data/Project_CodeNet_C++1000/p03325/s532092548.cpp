#include<bits/stdc++.h>
using namespace std;
long long bai(long long N){
  long long count=0;
  while(N%2==0){
    N=N/2;
    count++;
  }
  return count;
}

int main(){
  int N;
  cin>>N;
  vector<long long>A(N);
  long long sum=0;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    sum=sum+bai(A.at(i));
  }
  cout<<sum<<endl;
}