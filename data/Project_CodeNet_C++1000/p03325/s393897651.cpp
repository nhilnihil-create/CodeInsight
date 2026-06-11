#include <bits/stdc++.h>
using namespace std;


int main() {
  long long N;
  cin>>N;
  
  vector<long long> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  long long sum=0;
  for(int i=0;i<N;i++){
    while(vec.at(i)%2==0){
      sum++;
      vec.at(i)=vec.at(i)/2;
    }
  }
  cout<<sum<<endl;
  
}