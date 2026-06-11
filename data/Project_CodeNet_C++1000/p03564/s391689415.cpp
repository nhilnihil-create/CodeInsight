#include <bits/stdc++.h>
using namespace std; 
int main() {
  int N;
  int K;
  int i=0;
  cin>>N>>K;
  int sum=1;
  while(i<N){
    if(sum>=K){
      sum+=K;
    }else{
      sum*=2;
    }
    i++;
  }
  cout<<sum<<endl;
}
