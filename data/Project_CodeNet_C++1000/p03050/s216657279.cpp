#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  long long ans=0;
  long long temp;
  for(long long i=1;i*i<=N;i++){
    if(N%i == 0 ){
      temp=i-1;
      if(i !=1 && N/(i-1)==N%(i-1)){
        ans+=temp;
      }
      temp=(N/i-1);
      if(N/i != 1 && N/(N/i-1)==N%(N/i-1)){
        ans+=temp;
      }
    }
  }

  cout<<setprecision(12)<<ans<<endl;
  return 0;
}
