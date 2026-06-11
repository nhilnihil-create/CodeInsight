#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
string S,T;
  cin>>S>>T;
  sort(all(S));
  sort(all(T));
  reverse(all(T));
  ll N=S.size();
  ll M=T.size();
for(ll i=0;i<min(N,M);i++) {
if(S[i]<T[i]) {
cout<<"Yes"<<endl;
  return 0;
}
  if(S[i]>T[i]) {
cout<<"No"<<endl;
    return 0;
  }
}
  
  if(N>=M) {
cout<<"No"<<endl;
  }
  else {
cout<<"Yes"<<endl;
  }
}
