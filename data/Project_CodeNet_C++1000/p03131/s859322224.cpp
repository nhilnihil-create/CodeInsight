#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll K, A, B; cin>>K>>A>>B;
  if(A-B+2>=0 || K<A+1) cout<<K+1<<endl;
  else{
    ll N=K-(A+1);
    if(N%2==0) cout<<B+(B-A)*(N/2)<<endl;
    if(N%2==1) cout<<B+(B-A)*((N-1)/2)+1<<endl;
  }
}