#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll A,B;
  cin>>A>>B;
  ll ans=max(A+B,A-B);
  ans=max(ans,A*B);
  cout<<ans<<endl;
}