#include <bits/stdc++.h>
using namespace std;


int main() {
  long N;
  cin>>N;
  long ans=0;
  for(int i=1;i<sqrt(N);i++){
    long M=N-i;
    if(M%i==0&&i<M/i) ans+=M/i;
  }
  cout<<ans<<endl;
}
