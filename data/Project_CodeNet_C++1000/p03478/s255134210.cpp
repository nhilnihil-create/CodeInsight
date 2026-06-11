#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B,i,j;
  cin>>N>>A>>B;
  int ans = 0;
  
  for(i=1;i<=N;i++){
    int sum = 0;
    j=i;
    while(j>=1){
      sum = sum + j % 10;
      j /= 10;
    }
    if(A<=sum && sum<=B){
      ans += i;
      //cout << i << endl;
    }

  }
  
  cout << ans;

}