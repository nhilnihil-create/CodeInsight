#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int N;
  cin>>N;
  int V[N],C[N];
  rep(i,N){
      cin>>V[i];
  }
  rep(i,N){
      cin>>C[i];
  }
  int profit;
  int sum=0;
  rep(i,N){
      profit=V[i]-C[i];
      if(profit>0){
          sum+=profit;
      }
  }
  
  cout<<sum<<endl;
  
}