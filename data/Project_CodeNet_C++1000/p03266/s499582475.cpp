#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,K;
  cin>>N>>K;
  long long c=N/K;
  long long d=0;
  if(K%2==0){
    if(N%K<K/2){
      d=c;
    }
    else{
      d=c+1;
    }
  }   
  cout<<c*c*c+d*d*d<<endl;
}
