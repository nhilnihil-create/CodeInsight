#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  int t=1;
  
  cin >>N>>K;
  
  for(int i=0;i<N;i++){
    if(t*2<t+K) t=t*2;
    else t=t+K;
    
  }
  
  cout << t <<endl;
  
}