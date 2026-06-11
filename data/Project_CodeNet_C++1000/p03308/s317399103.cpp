#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,a=1,b=10000000000;
    cin>>N;
  
  vector<long long> v(N);
  for(long long i=0;i<N;i++){
    cin>>v.at(i);
  }
  for(long long i=0;i<N;i++){
    if(v.at(i)>=a){
      a=v.at(i);
    }
  }
  for(long long i=0;i<N;i++){
    if(v.at(i)<=b){
      b=v.at(i);
    }
  }
  cout<<a-b<<endl;
}
    