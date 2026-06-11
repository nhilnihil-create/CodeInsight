#include <bits/stdc++.h>
using namespace std;



int main(){
  int N,K;
  cin>>N>>K;
  
  double sum;
  for(int i=1;i<=N;i++){
    int a=i;
    double tmp=1.0/N;
    while(a<K){
      a*=2;
      tmp/=2;
    }
    sum+=tmp;
  }
  cout<<fixed<<setprecision(12)<<sum<<endl;
}