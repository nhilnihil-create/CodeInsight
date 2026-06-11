#include <bits/stdc++.h>
using namespace std;

int main() {

long  K,A,B;
cin>>K>>A>>B;

if(B-A<=2){
  cout<<1+K<<endl;
  return 0;
}

long ans=1+(A-1);
K-=(A-1);

if(K%2==1) K--,ans+=1;
ans-= A*K/2;
ans += B*K/2;

cout<<ans<<endl;

}
