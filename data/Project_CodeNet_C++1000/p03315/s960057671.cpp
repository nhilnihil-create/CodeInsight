#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll ans=0;
  string S;
  cin>>S;
  for(auto x:S) {
    if(x=='+') {
ans++;
    }
    else {
ans--;
    }
  }
  
  cout<<ans<<endl;
}
