#include<bits/stdc++.h>
using namespace std;
#define long long long

int main(){
  long N, K;
  cin >> N >> K;
  if(K==0){
    cout << N*N << endl;
    return 0;
  }
  long count=0;
  for(int i=K+1; i<=N; i++){
    long num = N/i;
    count += num*(i-K);
    num = N- num*i;
    if(num>=K){
      count+=num-K+1;
    }
  }
  cout << count << endl;
  return 0;
}