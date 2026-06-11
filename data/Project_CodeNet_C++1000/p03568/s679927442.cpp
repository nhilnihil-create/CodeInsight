#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
int main(){

  int N;
  cin>>N;
  vector<int>A(N);
  ll p=1;
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
    p*=3;
  }
  ll subnum=1;
  for(int i=0;i<=N-1;i++){
  
    if(A[i]%2==0){
    
      subnum*=2;
    }
    else subnum*=1;
  }
  cout<<p-subnum;
}