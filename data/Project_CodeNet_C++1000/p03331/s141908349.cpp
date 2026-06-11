#include <bits/stdc++.h>
using namespace std;

int digitssum(int n){
  int ans=0;
  while(n != 0){
    ans+=n%10;
    n/=10;
  }
  return ans;
}

int main(){
  int N;
  cin>>N;
  int minans=1000000000;
  for(int i=1;i<=N-1;i++){
    int temp=0;
    temp=digitssum(i)+digitssum(N-i);
     minans=min(minans,temp);
  }
  cout<<minans<<endl;
  return 0;
}
    
    
  