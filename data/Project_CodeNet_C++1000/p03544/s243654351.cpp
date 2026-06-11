#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin >> N;
  
  vector<ll> vec(N+1);
  for(int i=0;i<=N;i++){
    if(i==0){
      vec[i]=2;
    }
    if(i==1){
      vec[i]=1;
    }
    if(i>1){
      vec[i]=vec[i-1]+vec[i-2];
    }
  }
  cout << vec[N] <<endl;
}
