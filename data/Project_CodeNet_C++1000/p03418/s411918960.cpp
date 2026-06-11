#include<bits/stdc++.h>
using namespace std;
int main(){
long long N,K;
  cin>>N>>K;
  long long sum=0;
  for(long long i=K+1; i<=N; i++){
    long long t=N/i;
    long long s=N%i;
   sum+=t*(i-K);
    if(s>=K && K!=0) sum+=s-K+1;
    if(s>=K && K==0) sum+=s-K;
  }
  cout<<sum<<endl;
}