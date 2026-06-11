#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
  ll ans=700;
  for(auto x:S) {
if(x=='o') {
ans+=100;
}
  }
cout<<ans<<endl;
}