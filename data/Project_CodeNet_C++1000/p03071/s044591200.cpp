#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll A,B;
  cin>>A>>B;
  ll ans=max(2*A-1,2*B-1);
  ans=max(ans,A+B);
  cout<<ans<<endl;
}
