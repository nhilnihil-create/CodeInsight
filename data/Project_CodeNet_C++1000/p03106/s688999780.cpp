#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,K;cin>>A>>B>>K;
  int ans=101;
  int count=0;
  while(1){
    ans--;
    if(A%ans==0 && B%ans==0) count++;
    if(count==K) break;
  }
  cout<<ans<<endl;
}
