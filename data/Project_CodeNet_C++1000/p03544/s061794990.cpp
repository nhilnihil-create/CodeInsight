#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

map<ll,ll> S;

ll ryuka(ll N) {
if(N==1) {
return 1;
}
  if(N==0) {
return 2;
  }
  
  if(!S.count(N-1)) {
    S[N-1]=ryuka(N-1);
  }

    if(!S.count(N-2)) {
S[N-2]=ryuka(N-2);
    }
  ll s=S[N-2]+S[N-1];
  return s;
}
 
int main() {
  ll N;
  cin>>N;
  cout<<ryuka(N)<<endl;
}
  
