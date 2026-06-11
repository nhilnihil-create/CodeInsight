#include <bits/stdc++.h>
using namespace std;

int main(){
  long long  N;
  cin>>N;
  long long a[N];
  long long cnt=0;
  long long temp=0;
  for(long long i=0;i<N;i++){
    cin>>a[i];
    temp=a[i];
    //cout<<temp<<endl;
    while(temp%2==0){
      temp/=2;
      cnt++;
    }
    //cout<<i<<" "<<temp<<" "<<cnt<<endl;
  }
  cout<<cnt<<endl;
  return 0;
}
  
       