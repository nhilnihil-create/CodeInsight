#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A; cin >>N;
  int sum=1;
  int kazu=0;
  for(int i=0;i<N;i++){
    cin>>A;
    if(A%2==0){
      kazu=2;
    }else{
      kazu=1;
    }
    sum*=kazu;
  }
  long long kotae;
  kotae=pow(3,N)-sum;
  cout<<kotae<<endl;
}