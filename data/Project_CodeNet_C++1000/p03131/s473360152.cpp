#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,A,B;
  cin >> N >> A>> B;
  
  if ((B-A)<=2){
    cout<<1+N<<endl;
    return 0;
  }
  long long sum=0;
  long long maxsum=1+N;
  
  N=N-(A-1);
  sum=A;
  sum=sum+(B-A)*(N/2);
  if(N%2==1){
      sum=sum+1;
    }
  maxsum=max(maxsum,sum);
  cout<<maxsum;
  return 0;
}