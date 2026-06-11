#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,m;
  long long ans;
  cin>>n>>m;
  if(n==1 && m==1) cout<<1<<endl;
  else if(n==1) cout<<m-2<<endl;
  else if(m==1) cout<<n-2<<endl;
  else {
    ans=(n-2)*(m-2);
    cout<<ans<<endl;
  }
}
